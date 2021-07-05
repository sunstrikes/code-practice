//
// Created by Sun,Minqi on 2021/7/4.
//

#include "reflective_visitor.h"
#include "classic_visitor.h"
#include "visitor_acyclic.h"
#include "std_visit.h"
#include <variant>

using namespace std;
using namespace visitor;

int main() {
    //reflective visitor
    AdditionExpression exp{new DoubleExpression(1.0),
                           new AdditionExpression{new DoubleExpression(2.0),
                                                  new DoubleExpression(3.0)}};
    visitor::ExpressionPrinter p;
    p.print(&exp);
    cout << p.str() << endl;

    //double dispatch wiki: https://en.wikipedia.org/wiki/Double_dispatch
    //问题原因是虚函数是动态分派的, 但重载函数始终是静态的
    //相当于在动态函数外包了一层虚函数, 用来解决分派问题
    //访问者是一个接口，它拥有一个visit方法，这个方法对访问到的对象结构中不同类型的元素作出不同的反应
    cout << endl << "Classic Visitor:" << endl;
    auto e = new classic::AdditionExpression{
            new classic::DoubleExpression{1},
            new classic::SubtractionExpression{
                    new classic::DoubleExpression{2},
                    new classic::DoubleExpression{3}
            }
    };
    classic::ExpressionPrinter p1;
    classic::ExpressionEvaluator eval;
    p1.visit(e);
    eval.visit(e);
    cout << p1.str() << " = " << eval.result << endl;

    cout << endl << "Acyclic Visitor:" << endl;
    auto e2 = new acyclic::AdditionExpression{new acyclic::DoubleExpression{1},
                                              new acyclic::AdditionExpression{
                                                      new acyclic::DoubleExpression{2},
                                                      new acyclic::DoubleExpression{3}
                                              }
    };
    acyclic::ExpressionPrinter p2;
    p2.visit(*e2);
    cout << p2.str() << endl;

    cout << endl << "std::visit:" << endl;
    //variant & visit用法: https://zhuanlan.zhihu.com/p/57530780
    PrintVisitor stdp;
    std::variant<int, string> var;
    var = 221;
    std::visit(stdp, var);
    var = "house";
    std::visit(stdp, var);
    std::visit([](auto &arg) {
        //当T是引用类型，decay<T>::type返回T引用的元素类型；
        //当T是非引用类型，decay<T>::type返回T的类型
        using T = decay_t<decltype(arg)>;
        if constexpr (is_same_v<T, string>) {
            cout << "A house called " << arg.c_str() << "\n";
        } else {
            cout << "House number " << arg << "\n";
        }
    }, var);

    return 0;
}