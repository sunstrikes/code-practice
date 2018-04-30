class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int maxx = numeric_limits<int>::min();
        priority_queue<pair<int, int>, vector<pair<int,int>>, std::greater<pair<int,int>>> pq;

        for(int i = 0; i< nums.size(); ++i) {
            auto &num = nums[i];
            if (!num.empty()) {
                int tmp = num.front();
                maxx = std::max(tmp, maxx);
                pq.push({tmp, i});
            }
        }
        vector<int> res;
        vector<int> index(nums.size(), 0);
        res.push_back(pq.top().first);
        res.push_back(maxx);
        int range = maxx - pq.top().first;
        while(pq.size() == nums.size()) {
            auto t = pq.top();
            if (maxx - t.first < range){
                range = maxx - t.first;
                res[0] = t.first;
                res[1] = maxx;
            }
            pq.pop();
            index[t.second]++;
            if (index[t.second] < nums[t.second].size()) {
                int aa = nums[t.second][index[t.second]];
                pq.push({aa, t.second});
                maxx = std::max(maxx, aa);
            }
        }
        return res;
    }
};