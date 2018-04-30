class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        multiset<pair<int, int>> m;
        for(int i=0;i<profits.size();++i){
            if (profits[i] == 0){
                continue;
            }
            if (capital[i]<=w){
                pq.push(profits[i]);
            }else {
                m.emplace(capital[i], profits[i]);
            }
        }
        int res = w;
        while(k>0 && pq.size()){
            --k;
            res += pq.top();pq.pop();
            for(auto i = m.begin(); !m.empty() && i->first <= res; i = m.erase(i)) {
                pq.push(i->second);
            }
        }
        return res;
    }
};