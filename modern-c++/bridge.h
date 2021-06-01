//
// Created by SunStriKE on 2018/5/1.
//

#pragma once

#include "util.h"
namespace bridge {
    class Imp {
    public:
        Imp() { std::cout << "imp()" << std::endl; }

        ~Imp() { std::cout << "~imp()" << std::endl; }

        void print() { std::cout << "imp print" << std::endl; }
    };

    class Sample {
    public:
        Sample() : _pimp(new Imp) { std::cout << "sample()" << std::endl; }

        ~Sample() {
            std::cout << "~sample()" << std::endl;
        }

        void print() {
            _pimp->print();
        }

    private:
        std::shared_ptr<Imp> _pimp;
    };

}
