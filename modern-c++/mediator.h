//
// Created by Sun,Minqi on 2021/6/24.
// 中介者模式
//

#pragma once

#include "util.h"
#include <boost/signals2.hpp>

namespace mediator {
    struct EventData {
        virtual ~EventData() = default;

        virtual void print() const = 0;
    };

    struct ScoredData : EventData {
        std::string player_name;
        int goals_scored;

        ScoredData(std::string player_name, const int goals) : player_name(std::move(player_name)),
                                                               goals_scored(goals) {}

        void print() const override {
            std::cout << player_name << "has scored, their goal=" << goals_scored << std::endl;
        }
    };

    //中介类，该类通常处理不同类之间的通信，并支持松耦合，使代码易于维护
    struct Game {
        boost::signals2::signal<void(EventData *)> events;
    };

    struct Player {
        std::string name;
        int goals_scored = 0;
        Game &game;

        Player(std::string name, Game &game) : name(std::move(name)), game(game) {}

        void score() {
            ++goals_scored;
            ScoredData data{name, goals_scored};
            game.events(&data);
        }
    };

    struct Coach {
        Game &game;

        explicit Coach(Game &game) : game(game) {
            game.events.connect([](EventData *e) {
                auto data = dynamic_cast<ScoredData *>(e);
                if (data) {
                    std::cout << "Coach: well done, name=" << data->player_name << ", goal=" << data->goals_scored
                              << std::endl;
                }
            });
        }
    };
}