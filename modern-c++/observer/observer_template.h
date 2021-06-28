//
// Created by SunStriKE on 2021/6/28
//

#pragma once

#include "../util.h"

namespace observer {
    template<class T>
    struct Observer {
        virtual void field_changed(T &source, const std::string &field_name) = 0;

        static int listener_id;

        int get_id() { return _unique_id; }

    protected:
        int _unique_id{};
    };

    template<class T>
    struct Observable {
        void subscribe(const std::shared_ptr<Observer<T>> &listener) {
            std::lock_guard<std::mutex> guard(_mtx);
            _listeners.push_back(listener);
        }

        void unsubscribe(const std::shared_ptr<Observer<T>> &listener) {
            std::lock_guard<std::mutex> guard(_mtx);
            std::erase(std::remove_if(_listeners.begin(), _listeners.end(),
                                      [&listener](const std::weak_ptr<Observer<T>> &ptr) {
                                          auto sp = ptr.lock();
                                          if (sp) {
                                              return sp->get_id() == listener->get_id();
                                          } else {
                                              return true;
                                          }
                                      }), _listeners.end());
        }

        void notify(T &source, const std::string &name) {
            //在notify中为了避免调用回调函数使得一直持有锁, 导致另一个线程subscribe卡住等问题
            //先copy一份_listeners, 然后释放锁
            std::vector<std::weak_ptr<Observer<T>>> copy_listeners;
            {
                std::lock_guard<std::mutex> guard(_mtx);
                std::erase(std::remove_if(_listeners.begin(), _listeners.end(),
                                          [&copy_listeners](const std::weak_ptr<Observer<T>> &ptr) {
                                              std::shared_ptr<Observer<T>> sp = ptr.lock();
                                              if (sp) {
                                                  copy_listeners.push_back(ptr);
                                                  return false;
                                              } else {
                                                  return true;
                                              }
                                          }), _listeners.end());
            }
            for (auto &ptr: copy_listeners) {
                std::shared_ptr<Observer<T>> sp = ptr.lock();
                if (sp) {
                    sp->field_changed(source, name); //回调
                }
            }
        }

    private:
        std::vector<std::weak_ptr<Observer<T>>> _listeners;
        std::mutex _mtx;

    };


    struct Person : Observable<Person> {
    public:
        [[nodiscard]] int get_age() const { return _age; }

        void set_age(int age) { _age = age; }

        Person() {
            _age = 0;
        }

        [[nodiscard]] bool is_adult() const { return _age >= 18; }

    private:
        int _age;
    };


    struct PersonListener : Observer<Person> {
        PersonListener() {
            Observer<Person>::_unique_id = Observer<Person>::listener_id++;
            std::cout << "added PersonListener id=" << _unique_id << std::endl;
        }

        void field_changed(Person &source, const std::string &field_name) override {
            std::cout << "field[" << field_name << "] watched, value changed to:" << source.get_age() << std::endl;
        }
    };

    struct AdultListener : Observer<Person>, std::enable_shared_from_this<AdultListener> {
        AdultListener() {
            Observer<Person>::_unique_id = Observer<Person>::listener_id++;
            std::cout << "added AdultListener id=" << _unique_id << std::endl;
        }

        void field_changed(Person &source, const std::string &field_name) override {
            if (field_name == "age") {
                if (source.is_adult()) {
                    source.unsubscribe(shared_from_this());
                }
            }
        }
    };
}

