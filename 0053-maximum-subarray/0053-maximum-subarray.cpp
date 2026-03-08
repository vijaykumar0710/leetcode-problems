class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int t=nums[0];
        int res=nums[0];
        for(int i=1;i<n;i++){
            t=max(t+nums[i],nums[i]);
            res=max(res,t);
        }
        return res;
    }
};