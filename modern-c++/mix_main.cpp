//
// Created by Sun,Minqi on 2021/5/28.
//

#include "bridge.h"
#include "composite.h"
#include "flyweight.h"
#include "interpreter.h"
#include "iterator.h"
using namespace std;
using namespace bridge;
using namespace interpreter;
using namespace composite;
using namespace iterator;
int main() {
    cout << "Bridge Pattern:" << endl;
    /*
     * 桥接器的优点:
     *     1. 大量的实现细节可以隐藏到Impl类的内部, 不用担心成员权限, Impl只会暴露public接口
     *     2. 更改Impl的实现不会引发兼容性问题
     *     3. Impl的实现可以全部放到cpp文件中, 这样就避免了大量的像vector等库引入到.h文件里面
     *     类似于brpc中的proto Impl实现!
     */
    Sample sample;
    sample.print();
    cout << "Composite Pattern:" << endl;
    Neuron n1, n2;
    n1.connect_to(n2);

    cout << n1 << n2 << endl;

    Layer l1{5};
    Neuron n3;
    l1.connect_to(n3);

    cout << "Neuron " << n3._id << endl << n3 << endl;
    cout << "Layer " << endl << l1 << endl;

    Layer l2{ 2 }, l3{ 3 };
    l2.connect_to(l3);
    cout << "Layer l2" << endl << l2;
    cout << "Layer l3" << endl << l3 << endl << endl;

    cout << "Flyweight Pattern:" << endl;
    //避免大量的string对象存储, 更改为hash存储
    flyweight::User a{"a", "A"};
    flyweight::User b{"b", "B"};
    cout << a.get_first_name() << endl;
    cout << b.get_last_name() << endl;

    /*
     * 解释器模式
     * 优点: 可以容易地改变和扩展文法，因为使用类来表示文法规则，可用继承来改变或者扩展该文法。
     * 缺点: 为每一条规则至少定义了一个类，因此包含许多规则的文法可能难以维护和管理。当文法非常复杂时，使用其他技术如语法分析程序或编译器声称器
     */
    cout << endl;
    cout << "Interpreter Pattern: " << endl;
    Context interpret_context{"in", "out"};
    TerminalExpression exp1;
    NonTerminalExpression exp2(&exp1);
    exp1.interpret(&interpret_context);
    exp2.interpret(&interpret_context);
    /*
     * 迭代器模式
     * 用来顺序遍历数据结构
     */
    cout << endl;
    cout << "Iterator Pattern: " << endl;
    BinaryTree<int> iter_tree{new Node<int>{2, new Node<int>{1}, new Node<int>{3}}};
    for (auto iter = iter_tree.begin(); iter != iter_tree.end(); ++iter) {
        cout << "Iterator: " << (*iter).value << endl;
    }
    return 0;
}