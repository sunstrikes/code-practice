//WTF negativ numbers is useless!!
class Solution {
public:
    bool isPalindrome(int x) {
       if(x<0) return false;
       int tmp =abs(x);
       int  res =0;
       while(tmp!=0){
         res*=10;
         res+=tmp%10;
         tmp=tmp/10;
       }
     //  cout<<res<<endl;
       return abs(x)==res;
    }
};
