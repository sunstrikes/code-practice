class Solution {
public:
void reverse(string &s,int begin,int end){
    char tmp;
    while(begin<end){
        tmp = s[begin];
        s[begin] = s[end];
        s[end] = tmp;
        begin ++;
        end --;
    }
}
void trim(string &s)
{
    string res="";
    if (s.empty())
    {
        return;
    }
    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    int end = s.size()-1;
    for(int i =0;i<end;i++){
        if(s[i]==' '&&s[i+1]!=' '){
            res.push_back(' ');
        }else if(s[i]!=' '){
            res.push_back(s[i]);
        }
    }
      if(end>=0)
        res.push_back(s[end]);
    s = res;
}
void reverseWords(string &s) {
    trim(s);
    int begin  = 0;
    int n= s.size();
    int end = 0;
    reverse(s,0,n-1);
    for(int i =0;i<n;i++){
        if(s[i]==' '){
            if(begin<n&&end<=n)
                reverse(s,begin,end-1);
            else
                break;
            end = begin = i+1;
        }else{
            end++;
        }
    }
    reverse(s,begin,end-1);
    cout<<s<<endl;
} 
};