class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int max_idx=0;
        for(int i=0;i<n;i++){
            if(i!=n-1 && nums[i]==0 && max_idx<=i) return false;
            max_idx=max(max_idx,i+nums[i]);
        }
        return true;
    }
};