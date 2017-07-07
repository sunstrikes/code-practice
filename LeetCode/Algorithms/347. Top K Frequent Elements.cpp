class Solution {
public:
    class CompareDist
    {
    public:
        bool operator()(pair<int,int> n1,pair<int,int> n2) {
            return n1.second<n2.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        vector<int> res;
        for(auto &it:nums){
            ++map[it];
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, CompareDist> pq;
        for(auto it = map.begin();it!=map.end();it++){
            pq.push(make_pair(it->first, it->second));
        }
        for(int i = 0;i<k;i++){
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
        
    }
};