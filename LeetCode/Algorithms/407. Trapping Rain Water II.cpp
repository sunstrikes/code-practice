/*
我们同样每次应该先选取边界最小的高度，所以很自然的可以想到应该用优先队列来保存周围边界（小顶堆）．
在我们访问过了一个点之后要继续往矩形内部遍历，这样还需要保存一个点的位置．
为了防止再次访问已经访问过的点还需要用一个数组来标记每个点的访问状态．
*/
using pa = pair<int, int>;
pa operator-(pa &x, pa& y){
    return {x.first-y.first, x.second-y.second};
}
class Solution {
public:
    int trapRainWater(vector<vector<int>>& h){
        unordered_set<int> visited;
        vector<pa> dis = {{0,1},{1,0},{-1,0},{0,-1}};
        auto func = [&](pa &x, pa &y) -> bool{
            return h[x.first][x.second] > h[y.first][y.second];
        };
        priority_queue<pa, vector<pa>, decltype(func)> pq(func);
        int m = h.size();
        int n = m>0?h[0].size():0;
        for(int i= 0; i<h.size();++i){
            for(int j= 0; j<n;++j){
                if(i==0||j==0||i==m-1||j==n-1){
                    visited.insert(i*n+j);
                    pq.push({i,j});
                }
            }
        }
        int res = 0;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            for (auto &t: dis){
                auto tmp = top - t;
                if (tmp.first >= 0 && tmp.first < m && tmp.second >= 0 && tmp.second < n &&
                        visited.count(tmp.first*n + tmp.second) == 0){
                    int diff = h[tmp.first][tmp.second] - h[top.first][top.second];
                    cout<<diff<<endl;
                    if (diff < 0) {
                        h[tmp.first][tmp.second] -= diff;
                        res -= diff;
                    }
                    visited.insert(tmp.first*n + tmp.second);
                    pq.push(tmp);
                }
            }
        }
        return res;
    }
};