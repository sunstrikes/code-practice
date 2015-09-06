/*
Author:SunStrike
Language:c++
Complexity:O(m+n)
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int mid = 0;
        int status =1;
        int m = nums1.size(), n = nums2.size();
        if((m+n)%2==1){
            mid = (m+n+1)/2;
            status =1;
        }else{
           mid = (m+n)/2;
           status =2 ;
        }
        int x1=0,x2=0;
        int tmp=0;
        double res =0;
        for(int i =0 ;i<mid;i++){
            if(x1<m&&x2<n){
               if(nums1[x1]>nums2[x2]){
                  tmp = nums2[x2];x2++;
               }else{
                  tmp = nums1[x1];x1++;
              }
            }else if(x1>=m){
               tmp = nums2[x2];x2++;
            }else if(x2>=n){
              tmp = nums1[x1];x1++;
            }
        }
        if(status ==1){
            return (double) tmp;
        }else{
            if(x1<m&&x2<n){
                res =(tmp+min(nums1[x1],nums2[x2]))/2.0;
            }else if(x1>=m){
                res = (tmp+nums2[x2])/2.0;
            }else{
                res = (tmp+nums1[x1])/2.0;
            }
            return res;
        }
    }
};
