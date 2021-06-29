//
// Created by Sun,Minqi on 2021/6/28.
//

#include "observer_template.h"
#include "observer_signal.h"
using namespace std;
using namespace observer;
int main() {
    /*
     * 优点： 1、观察者和被观察者是抽象耦合的。 2、建立一套触发机制。
     * 缺点： 1、如果一个被观察者对象有很多的直接和间接的观察者的话，将所有的观察者都通知到会花费很多时间。
     *       2、如果在观察者和观察目标之间有循环依赖的话，观察目标会触发它们之间进行循环调用，可能导致系统崩溃。
     *       3、观察者模式没有相应的机制让观察者知道所观察的目标对象是怎么发生变化的，而仅仅只是知道观察目标发生了变化。
     */
    cout << "Template Observer Pattern:" << endl;
    Person person;
    auto pl = make_shared<PersonListener>();
    auto al = make_shared<AdultListener>();
    person.subscribe(pl);
    person.subscribe(al);
    person.set_age(10);
    person.set_age(18);
    person.set_age(21);

    cout << endl << "Signal Observer Pattern" << endl;
    Person2 p2;
    //需要多个observer的时候, 通过connection数组解决
    auto conn = p2.field_changed.connect([](Person2& source, const std::string& name){
       std::cout << "[PersonListener2]: field[" << name << "] watched, value changed to:" << source.get_age() << std::endl;
    });
    p2.set_age(20);
    conn.disconnect();
}