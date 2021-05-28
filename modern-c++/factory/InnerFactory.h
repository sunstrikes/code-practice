//
// Created by Sun,Minqi on 2021/5/27.
//

#pragma once
#include "../util.h"
class Points{
private:
    Points(float x, float y) :x(x), y(y) {}

public:
    struct InnerFactory{
    public:
        InnerFactory(){}
        static Points newNormal(float x, float y) {
            return Points(x, y);
        }
        static Points newPolar(float r, float theta) {
            return Points(r * std::cos(theta), r * std::sin(theta));
        }
    };

    friend std::ostream& operator<<(std::ostream& os, Points& obj) {
        os << "Point[" << obj.x << ", " << obj.y << "]";
        return os;
    }
    float x, y;
    typedef InnerFactory Factory;
};


