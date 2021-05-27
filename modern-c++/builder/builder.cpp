//
// Created by Sun,Minqi on 2021/5/26.
//
#include "../util.h"
//fluent builder
#include "FluentBuilder.h"
#include "GroovyStyleBuilder.h"
#include "CompositeBuilder.h"
using namespace std;

int main() {
    //fluent builder
    FluentBuilder fluent("root");
    fluent.add_tag("rl", "a").add_tag("rl", "b");
    fluent.add_tag2("rl", "c")->add_tag2("rl", "d");
    cout << "FluentBuilder res:" <<endl;
    fluent.print();
    //GroovyStyleBuilder 避免了手动调用的tag添加, 通过构造函数实现initialier_list的批量构造child tag
    RL bu1 {
        TL {"value1"},
        TL {"value2"}
    };
    cout << "\nGroovyStyle builder res" << endl;
    cout << bu1 << endl;
    //CompositeBuilder 不同子功能的builder进行了组合.
    Person p = Person::create()
            .lives().address("beijing").post_code("100001")
           .works().company("tencent").income(1);
    cout << "\nCompositeBuilder res: " <<endl;
    cout << p << endl;
}