class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string x = to_string(N);
        int i = 0;
        for (; i < x.size() - 1; ++i) {
            if (x[i] > x[i+1]){
                break;
            }
        }
        if (i == x.size() - 1) return N;
        while(i >= 1 && x[i-1] >= x[i]) i--;
        x[i] -= 1;
        for(int j = i+1;j < x.size();++j) {
            x[j] = '9';
        }
        return stoi(x);
    }
};
