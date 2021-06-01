//
// Created by Sun,Minqi on 2021/5/28.
//

#include "bridge.h"
using namespace std;
using namespace bridge;
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

    return 0;
}