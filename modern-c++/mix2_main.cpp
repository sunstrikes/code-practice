//
// Created by Sun,Minqi on 2021/6/24.
//

#include "util.h"
#include "mediator.h"
#include "memento.h"
using namespace std;
using namespace mediator;
using namespace memento;
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
    /*
     * 备忘录模式:
     * 通过Memento在不破坏封装的前提下，捕获一个对象的内部状态，
     *     并在该对象之外保存这个状态，这样可以在以后将对象恢复到原先保存的状态
     * 优点: 1.提供了一种状态恢复的实现机制，使得用户可以方便地回到一个特定的历史步骤
     *      2. 实现了信息的封装，一个备忘录对象是一种原发器对象的表示，不会被其他代码改动
     * 缺点: 1. 资源消耗过大，如果类的成员变量太多，就不可避免占用大量的内存
     */
    cout << "Memento Pattern:" << endl;
    BankAccount ac(0);
    auto m = ac.deposit(100);
    ac.deposit(200);
    cout << ac;
    ac.restore(m);
    cout << ac;
    ac.balance_undo();
    cout << ac;
    ac.balance_redo();
    cout << ac;
    return 0;
}