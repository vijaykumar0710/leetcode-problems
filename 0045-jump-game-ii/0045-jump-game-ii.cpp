class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int max_idx=0;
        int min_jump=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0 && max_idx<nums[i]+i) min_jump++;
            max_idx=max(max_idx,nums[i]+i);
            if(max_idx>=n-1) return min_jump;
        }
        return -1;
    }
};