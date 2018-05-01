//
// Created by SunStriKE on 2018/5/1.
//

#ifndef MODERN_C_OBSERVER_H
#define MODERN_C_OBSERVER_H


#include <string>
#include <memory>
#include <iostream>
#include <vector>

using std::string;

class Observer;
class Blog {
public:
    Blog() {
        std::cout << "Blog()" << std::endl;
    }

    ~Blog() {
        std::cout << "~Blog()" << std::endl;
    }

    void notify(void);
    const string &get_name() const {
        return _name;
    }

    void set_name(const string &_name) {
        Blog::_name = _name;
    }
    const string &get_status() const {
        return _status;
    }

    void set_status(const string &_status) {
        Blog::_status = _status;
    }
    void add_oberver(const std::shared_ptr<Observer>& op) {
        _observer.push_back(op);
    }
private:
    string _name;
    string _status;
    std::vector<std::weak_ptr<Observer> > _observer;
    typedef std::vector<std::weak_ptr<Observer>>::iterator iter;
};

class Observer {
public:
    Observer(const string &name, const std::shared_ptr<Blog> &blog)
            : _name(name), _blog(blog) {
        std::cout << "Observer " << _name << " -> " << _blog.lock()->get_name() << std::endl;
    }
    void update() {
        std::cout<<_name << "get" << _blog.lock()->get_name()
                 <<_blog.lock()->get_status()<<std::endl;
    }
private:
    std::string _name;
    //使用weakptr引用资源， 不产生引用计数， 防止循环引用无法析构
    std::weak_ptr<Blog> _blog;
};



#endif //MODERN_C_OBSERVER_H
