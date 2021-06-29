//
// Created by Sun,Minqi on 2021/6/24.
//

#include "util.h"
#include "mediator.h"
#include "memento.h"
#include "state.h"
using namespace std;
using namespace mediator;
using namespace memento;
using namespace state;
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

    /*
     * 状态模式:
     * 优点： 1、封装了转换规则。
     * 2、枚举可能的状态，在枚举状态之前需要确定状态种类。
     * 3、将所有与某个状态有关的行为放到一个类中，并且可以方便地增加新的状态，只需要改变对象状态即可改变对象的行为。
     * 4、允许状态转换逻辑与状态对象合成一体，而不是某一个巨大的条件语句块。
     * 5、可以让多个环境对象共享一个状态对象，从而减少系统中对象的个数。
     * 缺点： 1、状态模式的使用必然会增加系统类和对象的个数。
     * 2、状态模式的结构与实现都较为复杂，如果使用不当将导致程序结构和代码的混乱。
     * 3、状态模式对"开闭原则"的支持并不太好，对于可以切换状态的状态模式，增加新的状态类需要修改那些负责状态转换的源代码，
     *    而且修改某个状态类的行为也需修改对应类的源代码
     */
    cout << endl << "State Pattern with boost::msm:" << endl;
    msm::back::state_machine<PhoneStateMachine> phone;

    auto info = [&]()
    {
        auto i = phone.current_state()[0];
        cout << "The phone is currently " <<
             state_names[i] << "\n";
    };

    info();
    phone.process_event(CallDialed{});
    info();
    phone.process_event(CallConnected{});
    info();
    phone.process_event(PlacedOnHold{});
    info();
    phone.process_event(PhoneThrownIntoWall{});
    info();

    // try process_event here :)
    phone.process_event(CallDialed{});

    cout << "We are done using the phone" << "\n";

    return 0;
}