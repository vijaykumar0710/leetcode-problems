class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>t(n,0);
        t[0]=nums[0];
        int res=nums[0];
        for(int i=1;i<n;i++){
            t[i]=max(t[i-1]+nums[i],nums[i]);
            res=max(res,t[i]);
        }
        return res;
    }
};