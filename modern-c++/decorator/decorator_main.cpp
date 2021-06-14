//
// Created by SunStriKE on 2021/6/10.
//
#include "dynamic.h"
#include "static_decorator.h"
#include "functional_decorator.h"

using namespace std;
using namespace decorator;

template<typename R, typename... Args>

auto make_logger(R (*func)(Args...), const string &name) {
    return Logger<R(Args...)>(
            std::function<R(Args...)>(func),
            name);
}

int main() {
    /*
     * dynamic的缺点:
     * 由于装饰类将Circle当成内部成员, 内部成员的方法无法直接通过接口来调度
     * 需要在装饰类里显式定义, 比较麻烦
    */
    cout << "Dynamic Decorator:" << endl;
    Circle circle{1.0};
    ColoredShape colored{circle, "red"};
    TransparencyShape trans{colored, 25.0};
    //trans.resize(3); 不行
    cout << trans.str() << endl << endl;

    /*
     * static的优点:
     * 通过模板在编译期将装饰类继承自Circle, 这样通过模板装饰可以完美解决调用内部类方法的问题
     * 另外通过可变参数模板实现构造函数串联
     * 缺点: 失去了运行期进行重组对象的便利性
     */
    cout << "Static Decorator:" << endl;
    StaticTransShape<StaticColoredShape<Circle>> static_color{25.0, "red", 1.0};
    static_color.resize(3);
    cout << static_color.str() << endl << endl;

    /*
     * functional:
     * 适用于将代码块或者特定函数进行wrap的操作
     */
    cout << "Functional Decorator" << endl;
    Logger1([]() { std::cout << "hello" << std::endl; }, "HelloFunc")();
    cout << "Template FuncDecorator" << endl;
    auto call_logger = make_logger(add, "add");
    auto ret = call_logger(2, 3);
    cout << "Result: " << ret << endl;
}