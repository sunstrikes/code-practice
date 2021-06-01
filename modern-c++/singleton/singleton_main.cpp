//
// Created by Sun,Minqi on 2021/5/27.
//

#include "Forward.h"
using namespace std;
class Test{
    int a, b, c;
public:
    Test(int a, int b, int c): a(a), b(b), c(c) {}
    void print() {
        cout << a << " " << b << "" << c << endl;
    }
};


int main() {
    //forward singleton
    //现代设计模式中尽量避免使用单例模式, 如果必须要用, 使用static成员来实现
    cout << "use std::forward singleton:" << endl;
    auto pInstance = forward_singleton::Singleton<Test>::Instance<int, int, int>(1, 2, 3);
    pInstance->print();
    forward_singleton::Singleton<Test>::DestroyInstance();
    pInstance = forward_singleton::Singleton<Test>::GetInstance(); //throw exception
    pInstance->print();
    return 0;
}