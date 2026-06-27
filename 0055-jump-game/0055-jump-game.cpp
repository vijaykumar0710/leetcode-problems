class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        int max_jump=0;
        for(int i=0;i<n;i++){
            max_jump=max(max_jump,i+nums[i]);
            if(max_jump>=n-1) return true;
            if(max_jump==i) return false;
        }
        return max_jump>=n-1;
    }
};