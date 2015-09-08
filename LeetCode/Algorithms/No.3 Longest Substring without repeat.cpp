
//First time o(n^2) 超时
/*
    void init(int * loc){
       for(int i=0;i<95;i++){
        loc[i]=-1;
       }
    }
    int numberOfLoc(int * loc){
       int length =0;
      for(int i =0;i<95;i++){
         if(loc[i]!=-1){
            length++;
         }
       }
       return length;
    }
    int lengthOfLongestSubstring(string s) {
        int Max =0;
        int location[95];
        int length;
      // memset(location,-1,sizeof(int)*26);
        init(location);
        for(int i=0;i<s.size();i++){
            if(location[s[i]-'!']==-1){
                location[s[i]-'!']=i;
            }else{
                length = numberOfLoc(location);
               Max = Max<length?length:Max;
               i=location[s[i]-'!'];
               //memset(location,sizeof(int)*26,-1);
               init(location);
            }
        }
        length = numberOfLoc(location);
       Max = Max<length?length:Max;
        return Max;
    }
    */
//72ms  i和j都只遍历s一次，所以时间复杂度为O(N)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0, j = 0; //i是候选字符串的起点， j是候选字符串的终点。
        int max_length = 0;
        int cur_length = 0;
        bool exist[256] = { false };
        while (j < n) {
            if (!exist[s[j]]) {
                exist[s[j]] = true;  //遍历过，记录为true
                j++;
            } else {
                while(s[i]!= s[j]) {
                    exist[s[i]] = false;
                    //新候选字串从第一个重复字符(当s[i] == s[j]时候的i)的后一位开始算，之前的i不算，等效于没有被扫描到，所以设为false.
                    i++;
                }
                i++;
                j++;
            }
            cur_length = j - i;
            max_length = max_length > cur_length ? max_length : cur_length;
        }
        return max_length;
    }
};
