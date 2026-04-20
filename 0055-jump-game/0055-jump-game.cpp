class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n-1;i++){
           if(nums[i]==0 && i==maxi) return false;
           maxi=max(maxi,nums[i]+i);
           if(maxi>=n-1) return true;
        }
        return true;
    }
};