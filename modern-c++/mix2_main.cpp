//
// Created by Sun,Minqi on 2021/6/24.
//

#include "util.h"
#include "mediator.h"
using namespace std;
using namespace mediator;
int main() {
    /*
     * 中介者模式:
     * 优点: 1. 降低了类的复杂度，将一对多转化成了一对一。
             2. 各个类之间的解耦，减少对象之间的关联性，让每一个对象都能够独立
     * 缺点: 1.中介者会庞大，变得复杂难以维护。
             2. 如果有大量的功能模块需要中介者，那么担任中介者的角色类将会因为担任大量的中介者角色而容易产生操作接口爆炸的情况。
     */
    cout << "Mediator Pattern with events:" << endl;
    Game game;
    Player a{"A", game};
    Player b{"B", game};
    Coach coach(game);
    a.score();
    a.score();
    b.score();
    return 0;
}