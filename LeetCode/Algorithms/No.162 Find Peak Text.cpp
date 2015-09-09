
//Just tarvelsal vector and settle th boundary
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int index =0;
        if(nums.size()==1) return 0;
        for( int i =0;i<nums.size();++i){
            if(i-1==-1){
              if(nums[i]>nums[i+1]){
                index = i;
                break;
              }
            }else if(i+1==nums.size()){
              if(nums[i]>nums[i-1]){
                index = i ; break;
              }
            }
            else if(nums[i-1]<nums[i]&&nums[i]>nums[i+1])
            {index = i;
            break;
            }
        }
        return index;
    }
};
