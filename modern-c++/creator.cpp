#include "util.h"
using namespace std;
class Foo{
public:
    Foo() { cout << "foo" << endl;}
    Foo(Foo& foo){
        cout << "Copy Foo" <<endl;
    }
};
Foo make_foo1() {
    return Foo();
}

unique_ptr<Foo> make_foo2() {
    return make_unique<Foo>();
}


int main() {
    make_foo1(); //编译器优化避免了Foo copy
    make_foo2(); //不要依赖于编译器优化, 显式在堆上new
    return 0;
}
