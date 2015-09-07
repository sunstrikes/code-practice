/*
Author:SunStrike
Language:c++
WTF OVERFLOWS!!!!!
Using longlong !!
*/

class Solution {
public:
        int reverse(int y) {
        long long res=0;
        int tmp =0;
        long long x=y;
        if(x<0) x*=-1;
        //if(x==-2147483648) return 0;
        while(x!=0){
            tmp = x%10;
            res+=tmp;
            x=x/10;
            if(x>0)
              res*=10;
        }
        if(res<-2147483648||res>2147483647) return 0;
        if(y<0) res*=-1;
        return res;
    }
};
