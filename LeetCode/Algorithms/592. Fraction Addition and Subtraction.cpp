#include <numeric>
class Solution {
public:
    string fractionAddition(string e) {
        stringstream ss(e);
        int a, b, A=0, B=1;
        int tmp;
        char x;
        while(ss>>a>>x>>b) { //这个方法简直机智啊。。
            A = A * b + B*a;
            B *= b;
            tmp = abs(__gcd(A, B)); //__gcd编译器自带函数
            A/=tmp;
            B/=tmp;
        }
        return to_string(A) + "/" + to_string(B);
    }
};
