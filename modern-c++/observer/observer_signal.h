//
// Created by Sun,Minqi on 2021/6/29.
//

#pragma once

#include "../util.h"
#include <boost/signals2.hpp>

namespace observer {
    template<class T>
    struct Observable2 {
        virtual ~Observable2() = default;

        boost::signals2::signal<void(T &, const std::string &)> field_changed;
    };

    struct Person2 : Observable2<Person2> {
        void set_age(int age) {
            if (_age == age) return;
            _age = age;
            field_changed(*this, "age");
        }

        [[nodiscard]] int get_age() const { return _age; }

    private:
        int _age{0};
    };
}