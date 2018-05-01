//
// Created by SunStriKE on 2018/5/1.
//

#include "Observer.h"

void Blog::notify() {
    iter i = _observer.begin();
    while (i != _observer.end()) {
        //weak ptr没有访问能力
        std::shared_ptr<Observer> op(i->lock());
        if (op) { //判断对象是否析构
            op->update();
            ++i;
        } else {
            i = _observer.erase(i);
        }
    }
}
