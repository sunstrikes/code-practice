    //Using DP
    //base case : table[i][i]= true and find table[i][i+1]==true
    //ifs[i]==s[j] && table[i+1][j-1] =>table[i][j]=true;
    string longestPalindrome(string s) {
      bool table[1000][1000] = {false};
      int maxLen = 1;
      int longestBegin = 0;
      for(int i =0 ; i< 1000;i++){
        table[i][i] = true;
      }
      for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]){
            table[i][i+1] = true;
            maxLen = 2;
            longestBegin = i;
        }
      }
      for(int len = 3; len <=s.size();++len){
        for(int i = 0;i<s.size()-len+1;++i){
            int j = i+len-1;
            if(s[i]==s[j]&&table[i+1][j-1]){
                table[i][j]=true;
                longestBegin = i;
                maxLen = len;
            }
        }
      }
      return s.substr(longestBegin,maxLen);
    }
