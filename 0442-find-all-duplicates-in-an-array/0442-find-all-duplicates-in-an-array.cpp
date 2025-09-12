class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>res;
        int i=0,n=nums.size();;
        while(i<n){
            int correct_idx=nums[i]-1;
            if(nums[i]!=nums[correct_idx]) swap(nums[i],nums[correct_idx]);
            else i++;
        }
        for(int i=0;i<n;i++) if(nums[i]!=i+1) res.push_back(nums[i]);
        return res;
    }
};