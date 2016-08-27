//my bfs 208ms
int legal(string &s) {
	int count = 0;
	for (auto x : s) {
		if (x == '(') {
			count++;
		}else if(x ==')'){
			count--;
			if (count < 0)
				return false;
		}
	}
	return (count == 0);
}
void bfs(unordered_set<string> & res, string &s) {
	unordered_set<string> st;
	queue<string> q;
	q.push(s);
	int len = s.size()+1;
	while (!q.empty()) {
		string x = q.front();
		q.pop();
		if (x.size() == len) {
			break;
		}
		for (int i = 0; i < x.size(); ++i) {
			if (x[i] != '(' && x[i] != ')')
				continue;
			string tmp = x.substr(0, i) + x.substr(i + 1);
			if (legal(tmp)) {
				len = tmp.size();
				res.insert(tmp);
			}
			else {
				if (st.count(tmp) == 0) {
					q.push(tmp);
					st.insert(tmp);
				}
			}
		}
	}
	return;
}
vector<string> removeInvalidParentheses(string s) {
    unordered_set<string> res;
	vector<string> vv;
	if (legal(s)) {
		vv.push_back(s);
		return vv;
	}
	bfs(res, s);
	for(auto it = res.begin();it!=res.end();it++){
	    vv.push_back(*it);
	}
	return vv;
}
//dfs 8ms too fast to stand...Orz
    void traverse(string&s, int pos, string v_s, unordered_set<string>& v, int left, int right, int pair)
    {
        if(s[pos] == '\0') 
        {
            if(!pair) v.insert(v_s);
            return ;
        }
        if(s[pos] == '(')
        {
            if(left) traverse(s, pos+1, v_s, v, left-1, right, pair);
            traverse(s, pos+1, v_s+"(", v, left, right, pair+1);
        }
        else if(s[pos] == ')')
        {
            if(right) traverse(s, pos+1, v_s, v, left, right-1, pair);
            if(pair) traverse(s, pos+1, v_s+")", v, left, right, pair-1);
        }
        else traverse(s, pos+1, v_s+s[pos], v, left, right, pair);
    }
    vector<string> removeInvalidParentheses(string s) {
        int left=0, right=0, pair=0;
        unordered_set<string> v;
        string v_s;
        for(auto c: s)
            if(c == '(') left++;
            else if(c == ')') left>0? left-- : right++;
        traverse(s, 0, v_s, v, left, right, pair);
        return vector<string>(v.begin(), v.end());
    }
