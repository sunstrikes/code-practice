//
// Created by Sun,Minqi on 2021/6/11.
//

#pragma once
#include <utility>

#include "../util.h"
namespace proxy {
    //这个有问题, 模板只能使用基础类型, 像string类这种, get方法有问题暂时无法解决
    //TODO get方法看看怎么优化
    template<class T>
    class PropertyProxy{
        T value;
    public:
        explicit PropertyProxy(T  v) {
            *this = v;
        }
        operator T() {  //get
            std::cout << "get value:" << value << std::endl;
            return value;
        }
        T& operator=(T input) { //set
            std::cout << "set value:" << input << std::endl;
            value = input;
            return value;
        }
    };
    struct Creature{
        PropertyProxy<int> a {10};
        PropertyProxy<std::string> b {"dfa"};
    };
}