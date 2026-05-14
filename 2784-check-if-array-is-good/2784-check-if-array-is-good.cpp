class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(nums[n-1]!=n-1) return false;
        for(int i=1;i<n;i++) if(i!=nums[i-1]) return false;
        return true;
    }
};