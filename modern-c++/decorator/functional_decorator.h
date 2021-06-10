//
// Created by Sun,Minqi on 2021/6/9.
//

#pragma once

#include <utility>

#include "../util.h"

namespace decorator {
    int add(int a, int b) {
        std::cout << "a[" << a << "] + b[" << b << "]" << std::endl;
        return a + b;
    }

    //方法1 缺点是无法改变函数的接口以及返回值
    class Logger1 {
        std::function<void()> func;
        std::string name;
    public:
        Logger1(std::function<void()> func, std::string name) : func(std::move(func)), name(std::move(name)) {}

        void operator()() const {
            std::cout << "before " << name << std::endl;
            func();
            std::cout << "after " << name << std::endl;
        }
    };

    //这里必须做一次显式特化, 不然下面编译会报错: explicit specialization of template class member function
    //TODO 还没搞清楚原理
    template <typename> struct Logger;
    //方法2, 通过可变模板参数+返回值定义的 function, 来实现灵活定制
    template<typename R, typename ...Args>
    class Logger<R(Args...)> {
        std::function<R(Args...)> func;
        std::string name;
    public:
        Logger(std::function<R(Args...)> func, std::string name) : func(std::move(func)), name(std::move(name)) {}
        R operator()(Args ...args) const {
            std::cout << "before " << name << std::endl;
            R result = func(args...);
            std::cout << "after " << name << std::endl;
            return result;
        }
    };
}