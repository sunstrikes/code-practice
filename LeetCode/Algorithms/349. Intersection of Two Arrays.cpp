class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> ss;
        vector<int> res;
        for(auto x:nums1){
            ss.insert(x);
        }
        sort(nums2.begin(), nums2.end());
        for(int i=0;i<nums2.size();i++){
            if((i == 0 || (nums2[i]!=nums2[i-1])) && ss.count(nums2[i])!=0){
                res.push_back(nums2[i]);
            }
        }
        return res;
    }
};