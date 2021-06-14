//
// Created by Sun,Minqi on 2021/6/12.
//

#include "pointer_chain.h"
#include "broker_chain.h"
using namespace chain;
using namespace std;
int main() {
    cout << "Pointer Chain:" << endl;
    Creature creature{"fox", 1, 1};
    AttackCreatureModifier att1{creature};
    AttackCreatureModifier att2{creature};
    AttackCreatureModifier att3{creature};
    att1.add(&att2);
    att1.add(&att3);
    att1.handle();
    cout << creature.attack << endl;

    cout << "Broker Chain:" << endl;
    Game game;
    Creature2 creature2{game, "Holy Knight", 1, 1};
    DoubleAttackModifier dm(game, creature2);
    DoubleAttackModifier dm2(game, creature2);

    cout << creature2 << endl;
    return 0;
}