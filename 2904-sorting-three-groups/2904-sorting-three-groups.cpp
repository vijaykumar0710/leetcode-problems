class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>sorted;
        for(int i=0;i<n;i++){
            auto it=upper_bound(sorted.begin(),sorted.end(),nums[i]);
            if(it!=sorted.end()) *it=nums[i];
            else sorted.push_back(nums[i]);
        }
        return n-sorted.size();
    }
};