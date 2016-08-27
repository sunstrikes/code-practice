class Solution {
public:
int maximumGap(vector<int>& nums) {
    int len = nums.size();
    if(len<2){
        return 0;
    }
    int minn = INT_MAX;
    int maxx = INT_MIN;
    for(int i=0;i<len;i++){
        minn = min(minn,nums[i]);
        maxx = max(maxx,nums[i]);       
    }
    vector<int> mins(len-1, INT_MAX);
    vector<int> maxs(len-1,INT_MIN);
    int gap = ceil(double(maxx-minn)/(len-1));
    for(int i:nums){
        if(i==minn || i==maxx)
            continue;
        int index = (i-minn)/gap;
        mins[index] = min(mins[index],i);
        maxs[index] = max(maxs[index],i);
    }
    int pre = minn;
    int ans = INT_MIN;
    for(int i=0;i<len-1;++i){
        if(mins[i]==INT_MAX && maxs[i]==INT_MIN)
            continue;
        ans = max(ans, mins[i]-pre);
        pre = maxs[i];
    }
    ans = max(ans,maxx - pre);
    return ans;
}
};