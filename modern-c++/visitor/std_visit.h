//
// Created by Sun,Minqi on 2021/7/5.
//

#pragma once
namespace visitor {
    struct PrintVisitor {
        template<class T>
        void operator()(T t) const {
            std::cout << typeid(t).name() << " = " << t << std::endl;
        }
    };

}