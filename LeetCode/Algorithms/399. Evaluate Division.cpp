#include<cmath>
class Solution {
public:
    double a[100][100];
    map<string, int> m;
    int visited[100];
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        int j = 0;
        for (int i =0 ; i<100; ++i) {
            for (int j=0;j<100;++j) {
                a[i][j] = 0.0;
            }
        }
        m.clear();

        int x, y;
        for(int i =0 ; i< equations.size(); ++i) {
            auto &tmp = equations[i];
            if (m.count(tmp.first) == 0) {
                m[tmp.first] = j++;
            }
            if (m.count(tmp.second) == 0) {
                m[tmp.second] = j++;
            }
            x = m[tmp.first];
            y = m[tmp.second];
            a[x][y] = values[i];
            a[y][x] = 1.0/values[i];
        }
        vector<double> res;
        for (int i = 0; i < queries.size(); ++i) {
            double r = 0;
            auto & tmp = queries[i];
            if (m.find(tmp.first) == m.end() || m.find(tmp.second) == m.end()) {
                res.push_back(-1.0);
                continue;
            }
            if (tmp.first == tmp.second) {
                res.push_back(1.0);
                continue;
            }
            x = m[tmp.first];
            y = m[tmp.second];
            memset(visited, 0, sizeof(visited));
            res.push_back(dfs(x,y, m.size()));
        }
        cout<<res[0]<<endl;
        return res;
    }
    double dfs(int x, int y, int sum) {
        visited[x] = 1;
        for (int i = 0; i < sum; i++) {
            if (x == i || visited[i]) continue;
            if (std::abs(a[x][i] - 0.0) > 0.000001){
                if (i == y) return a[x][y];
                double res = dfs(i, y, sum);
                if (std::abs(res + 1.0) > 0.000001) {
                    return a[x][i] * res;
                }
            }
        }
        visited[x] = 0;
        return -1.0;
    }
};