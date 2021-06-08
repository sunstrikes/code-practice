//
// Created by Sun,Minqi on 2021/6/8.
//
#pragma once
#include "dynamic.h"
namespace decorator{
    template<typename T>
    class StaticTransShape: public T{
    public:
        float transparency;

        template<class ...Args>
        explicit StaticTransShape(float transparency, Args ...args):
            transparency(transparency), T(std::forward<Args>(args)...) {}

        [[nodiscard]] std::string str() const {
            std::ostringstream oss;
            oss << T::str() << " has Transparency: " << transparency << "%";
            return oss.str();
        }
    };

    template<typename T>
    class StaticColoredShape: public T{
    public:
        std::string color;
        template<class ...Args>
        explicit StaticColoredShape(std::string color, Args ...args):
                color(std::move(color)), T(std::forward<Args>(args)...) {}

        [[nodiscard]] std::string str() const {
            std::ostringstream oss;
            oss << T::str() << " has Color: " << color;
            return oss.str();
        }
    };
}