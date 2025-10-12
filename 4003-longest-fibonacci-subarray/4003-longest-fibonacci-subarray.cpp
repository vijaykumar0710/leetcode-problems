class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size(),len=2,res=0;
        for(int i=0;i<n-2;i++){
          if(nums[i]+nums[i+1]==nums[i+2]) len++;
          else{ res=max(res,len); len=2; }
        }
        res=max(res,len);
        return res;
    }
};