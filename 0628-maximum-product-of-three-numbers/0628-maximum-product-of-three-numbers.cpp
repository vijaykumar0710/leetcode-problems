class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int res1=1,res2=1,res3=1;
        res1*=nums[0]*nums[n-1]*nums[n-2];
        res2*=nums[0]*nums[1]*nums[n-1];
        res3*=nums[n-1]*nums[n-2]*nums[n-3];
        return max({res1,res2,res3});
    }
};