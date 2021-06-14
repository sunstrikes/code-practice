//
// Created by Sun,Minqi on 2021/6/12.
//

#pragma once

#include "../util.h"

namespace chain {
    /*
     * 责任链模式:
     * 使用一个类似链表的方法实现
     * 保证当多个对象修改Creature的时候, 可以保证对于属性修改的顺序发生
     */
    struct Creature {
        std::string name;
        int attack, defense;
        Creature(std::string name, int attack, int defense): name(std::move(name)), attack(attack), defense(defense) {}
    };

    struct CreatureModifier {
        CreatureModifier* _next;
        Creature &_creature;
        explicit CreatureModifier(Creature &creature) : _creature(creature) {
            _next = nullptr;
        }

        void add(CreatureModifier* cm) {
            if (_next) { _next->add(cm); }
            else {
                _next = cm;
            }
        }


        virtual void handle()  {
            if (_next) _next->handle();
        }
    };

    struct AttackCreatureModifier: CreatureModifier{
    public:
        explicit AttackCreatureModifier(Creature &creature): CreatureModifier(creature) {}
        void handle() override {
            _creature.attack *= 2;
            std::cout << "attack modify *=2, now =" << _creature.attack << std::endl;
            CreatureModifier::handle();
        }
    };
}