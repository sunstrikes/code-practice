class Solution {
public:
	vector<int> exclusiveTime(int n, vector<string>& logs) {
		vector<int> res(n, 0);
		int id, preid,time, pretime;
		string op,preop;
		stack<int> st;
		map<int, int> seet;
		split(logs[0], preid, preop, pretime);
		st.push(preid);
		for (int i = 1; i < logs.size(); i++) {
			split(logs[i], id, op, time);
			if (op == "start") {
				if (preop == "start")
					res[preid] += time - pretime;
				else if (!st.empty()) {
					res[st.top()] += (time - pretime - 1);
				}
				st.push(id);
			}
			else {
				st.pop();
				if (preop == "start")
					res[id] += time - pretime + 1;
				else
					res[id] += time - pretime;
			}
			preid = id;
			preop = op;
			pretime = time;
		}
		return res;
	}
	void split(string a, int &id, string &op, int &time) {
		size_t pos = a.find_first_of(":");
		stringstream ss;
		ss << a.substr(0, pos);
		ss >> id;
		size_t pos2 = a.find_last_of(":");
		ss.clear();
		ss << a.substr(pos2 + 1);
		ss >> time;
		op = a.substr(pos + 1, pos2 - pos - 1);
	}
};