class Solution {
public:
    int findFinalValue(vector<int>& nums, int ori) {
        sort(nums.begin(),nums.end());
        for(auto x:nums) if(x==ori) ori*=2;
        return ori;
    }
};