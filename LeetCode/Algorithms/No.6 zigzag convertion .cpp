//using vector store every line
string convert(string s, int numRows) {
    vector<string> row(numRows,"");
    if(numRows ==1 ) return s;
    int tmp = 0;
    int direction =0;
    for(int i =0; i<s.size();i++){
       if(direction==0&&tmp<numRows){
          row[tmp].push_back(s[i]);
          tmp++;
          if(tmp == numRows){
            tmp = numRows-2;
            direction = 1;
          }
       }else if(direction ==1 &&tmp>=0){
          row[tmp].push_back(s[i]);
          tmp--;
          if(tmp == -1){
            tmp = 1;
            direction = 0;
          }
       }
    }
    string res;
    for(int i = 0 ;i< row.size();++i){
        res.append(row[i]);
    }
    return res;
}
