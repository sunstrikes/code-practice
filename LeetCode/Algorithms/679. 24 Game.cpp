class Solution {
public:
    vector<char> op = {'+', '-', '*', '/'};

    bool judgePoint24(vector<int> &nums) {
        vector<double> a;
        for (auto &t:nums) {
            a.push_back(t * 1.0);
        }
        return dfs(a);
    }

    bool dfs(vector<double> &a) {
        if (a.size() == 1) {
            return std::abs(a[0] - 24.0) <= 0.00001;
        }
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < a.size(); ++j) {
                if (i == j) continue;
                vector<double> res;
                for (int k = 0; k < a.size(); ++k) {
                    if (k != i && k != j)
                        res.push_back(a[k]);
                }
                for (auto &t: op) {
                    if (t == '/' && a[j] == 0.0) continue;
                    if ((t == '+' || t == '*') && i > j) continue; //+, *满足交换律
                    switch (t) {
                        case '+':
                            res.push_back(a[i] + a[j]);
                            break;
                        case '-':
                            res.push_back(a[i] - a[j]);
                            break;
                        case '*':
                            res.push_back(a[i] * a[j]);
                            break;
                        case '/':
                            res.push_back(a[i] / a[j]);
                            break;
                    }
                    if (dfs(res)) return true;
                    res.pop_back();
                }
            }
        }
        return false;
    }
};