//
// Created by Sun,Minqi on 2021/6/11.
//

#include "property.h"
#include "virtual.h"
using namespace std;
using namespace proxy;
int main() {
    //这个代理的作用是生成属性类似java的get/set方法.
    cout << "Property Proxy:" << endl;
    Creature creature;
    cout << creature.a << endl;
    creature.b = "hello";
    cout << endl;

    cout << "Virtual Proxy" << endl;
    //Virtual作用比如bitmap不想在构造函数初始化的时候就加载图片, 而是在draw的时候加载
    //可以通过Virtual代理的方式实现LazyLoad
    LazyBitmap bitmap("Dark-Souls");
    bitmap.draw();
    return 0;
}
