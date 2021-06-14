//
// Created by Sun,Minqi on 2021/6/10.
//

#pragma once

#include <functional>
#include <unordered_map>
#include "util.h"

namespace flyweight {
// 享元模式
// 在有大量细粒度对象时，有可能会造成内存溢出，我们把其中共同的部分抽象出来，
// 如果有相同的业务请求，直接返回在内存中已有的对象，避免重新创建
    class User {
        std::size_t last_name, first_name;
    public:
        User(const std::string &first, const std::string &last) : first_name{add(first)}, last_name{add(last)} {}

        static std::size_t add(const std::string &name) {
            key = std::hash<std::string_view>{}(name);
            auto iter = name_map.find(key);
            if (iter == name_map.end()) {
                name_map[key] = name;
            }
            return key;
        }

        [[nodiscard]] std::string &get_first_name() const {
            return name_map[first_name];
        }

        [[nodiscard]] std::string &get_last_name() const {
            return name_map[last_name];
        }

        static std::unordered_map<std::size_t, std::string> name_map;
        static std::size_t key;
    };

    std::unordered_map<std::size_t, std::string> User::name_map = {};
    std::size_t User::key = 0;
}