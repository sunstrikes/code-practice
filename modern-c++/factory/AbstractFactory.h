//
// Created by Sun,Minqi on 2021/5/27.
//

#pragma once

namespace AbstractFactory {
    class Drink {
    public:
        virtual void prepare(int volume) = 0;
    };

    class Tea : public Drink {
    public:
        void prepare(int volume) {
            std::cout << "tea need " << volume << "ml water" << std::endl;
        }
    };

    class Coffee : public Drink {
    public:
        void prepare(int volume) {
            std::cout << "coffee need " << volume << "ml water" << std::endl;
        }
    };

    class DrinkFactory {
    public:
        virtual std::unique_ptr<Drink> make() = 0;
    };

    class TeaFactory : public DrinkFactory {
    public:
        std::unique_ptr<Drink> make() {
            return std::make_unique<Tea>();
        }
    };

    class CoffeeFactory : public DrinkFactory {
    public:
        std::unique_ptr<Drink> make() {
            return std::make_unique<Coffee>();
        }
    };

    class Factory {
        std::map<std::string, std::unique_ptr<DrinkFactory>> _factory;
    public:
        Factory() {
            _factory["tea"] = std::make_unique<TeaFactory>();
            _factory["coffee"] = std::make_unique<CoffeeFactory>();
        }

        std::unique_ptr<Drink> make_drink(const std::string &type) {
            if (_factory.find(type) == _factory.end()) {
                return nullptr;
            }
            auto &fac = _factory[type];
            auto drink_ptr = fac->make();
            drink_ptr->prepare(200);
            return drink_ptr;
        }
    };
}