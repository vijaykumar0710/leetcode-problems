class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>t(n,1);
        for(int i=1;i<n;i++) t[i]=nums[i-1]<nums[i]?t[i-1]+1:1;
        for(int i=0;i+2*k<=n;i++) if(t[i+k-1]>=k && t[i+2*k-1]>=k) return true;
        return false;
    }
};