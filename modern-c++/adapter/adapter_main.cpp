//
// Created by Sun,Minqi on 2021/5/28.
//

#include "Adapter.h"
using namespace std;
using namespace adapter;
int main() {
    VectorRectangle rectangle(0,0,2,3);
    for (auto & x : rectangle) {
        Adapter tmp{x};
        cout << tmp << endl;
    }
    return 0;
}