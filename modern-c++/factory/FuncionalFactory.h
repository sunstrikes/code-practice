//
// Created by Sun,Minqi on 2021/5/27.
//

#pragma once

#include "../util.h"
#include "AbstractFactory.h"

namespace Functional {
    using AbstractFactory::Drink;
    using AbstractFactory::Tea;
    using AbstractFactory::Coffee;

    class FunctionalFactory {
        std::map<std::string, std::function<std::unique_ptr<Drink>()>> _factory;
    public:
        FunctionalFactory() {
            _factory["tea"] = []() {
                auto tea_ptr = std::make_unique<Tea>();
                tea_ptr->prepare(200);
                return tea_ptr;
            };
            _factory["coffee"] = []() {
                auto coffee_ptr = std::make_unique<Coffee>();
                coffee_ptr->prepare(50);
                return coffee_ptr;
            };
        }

        std::unique_ptr<Drink> make_drink(const std::string &type) {
            if (_factory.find(type) == _factory.end()) {
                return nullptr;
            }
            return _factory[type]();
        }
    };
}