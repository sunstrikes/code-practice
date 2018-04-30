#include <memory>
#include <functional>
#include <iostream>
#include <utility>
using namespace std;
/*
 * 工厂模式： c++11不需要传出指针创建
 * 抽象接口类应该是一些函数的集合。函数可以随意指定，拼装。
 * 将A::f与接口类回调函数绑定，可以优雅的实现工厂模式， 不需要虚继承
 */
class Interface{
public:
    Interface(const Interface&) = delete;
    typedef function<void(void)> callback;
    typedef function<int(int)> f_call;
    Interface(f_call f, callback g):call1(f), call2(g){}
    f_call call1;
    callback call2;
};

class A{
public:
    A(){cout<<"A()"<<endl;}
    ~A(){cout<<"~A()"<<endl;}
    int f(int x){cout<<"A::F()"<<x<<endl;}
    void g(void){cout<<"A::G()"<<endl;}
};

int main(){
    A a;
    using std::placeholders::_1;
    Interface base(bind(&A::f, &a, _1), bind(&A::g, &a));
    base.call1(1);
    base.call2();
    return 0;
}