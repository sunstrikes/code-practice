//
// Created by Sun,Minqi on 2021/6/12.
//

#pragma once

#include "../util.h"
#include <boost/signals2.hpp>

namespace chain {
    /*
     * broker chain:
     * 和pointer相比, 使用了boost::signal来注册Modifier, 避免持久化的改变对象
     * 相关改动会在Modifier析构后自动取消
     */
    struct Query {
        std::string creature_name;
        enum Argument {
            attack, defense
        } argument;
        int result;

        Query(std::string name, Argument argument, int result) : creature_name(std::move(name)), argument(argument),
                                                                 result(result) {}
    };

    struct Game {
        boost::signals2::signal<void(Query &)>
                queries;
    };

    struct Creature2 {
    private:
        Game &game;
        int attack, defense;
    public:
        std::string name;
        Creature2(Game &game, std::string name, int attack, int defense) : game(game), name(std::move(name)),
                                                                           attack(attack), defense(defense) {}

        [[nodiscard]] int get_attack() const {
            Query q{name, Query::Argument::attack, attack};
            game.queries(q);
            return q.result;
        }
        [[nodiscard]] int get_defense() const {
            Query q{name, Query::Argument::defense, defense};
            game.queries(q);
            return q.result;
        }
        friend std::ostream& operator<<(std::ostream& out, Creature2& obj) {
            out << obj.name
                << "  Attack:[" << obj.get_attack()
                << "], Defense:[" << obj.get_defense() << "]." << std::endl;
            return out;
        }
    };

    struct Creature2Modifier {
        Game& game;
        Creature2& creature;
        Creature2Modifier(Game& game, Creature2& creature): game(game), creature(creature) {}
    };

    struct DoubleAttackModifier: Creature2Modifier {
    private:
        boost::signals2::connection _conn;
    public:
        DoubleAttackModifier(Game& game, Creature2& creature): Creature2Modifier(game, creature) {
            _conn = game.queries.connect([&](Query& q){
               if (creature.name == q.creature_name && q.argument == Query::Argument::attack) {
                   q.result *= 2;
               }
            });
        }
        ~DoubleAttackModifier() {
            _conn.disconnect();
        }
    };

}