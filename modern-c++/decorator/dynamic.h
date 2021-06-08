//
// Created by Sun,Minqi on 2021/6/8.
//

#pragma once
#include <utility>

#include "../util.h"
namespace decorator{
    class Shape{
    public:
        //nodiscard 要求必须处理返回值, 否则报错
        [[nodiscard]] virtual std::string str() const = 0;
    };

    class ColoredShape: public Shape{
    public:
        Shape &shape;
        std::string color;
        ColoredShape(Shape& shape, std::string color): shape(shape), color(std::move(color)) {}
        [[nodiscard]] std::string str() const override {
            std::ostringstream oss;
            oss << shape.str() << " has Color: " << color;
            return oss.str();
        }
    };

    class TransparencyShape: public Shape{
    public:
        Shape &shape;
        float transparency;
        TransparencyShape(Shape& shape, float transparency): shape(shape), transparency(transparency) {}
        [[nodiscard]] std::string str() const override {
            std::ostringstream oss;
            oss << shape.str() << " has Transparency: " << transparency << "%";
            return oss.str();
        }
    };

    class Circle: public Shape{
    public:
        float radius;
        Circle(float radius):radius(radius) {}
        [[nodiscard]] std::string str() const override{
            std::ostringstream oss;
            oss << "Circle Radius: " << radius;
            return oss.str();
        }
        void resize(float rad) {
            radius = rad;
        }
    };
}