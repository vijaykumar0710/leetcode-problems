class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>temp;
        for(int i=0;i<n-1;i++) temp.push_back((nums[i]+nums[i+1])%10);
        return triangularSum(temp);
    }
};