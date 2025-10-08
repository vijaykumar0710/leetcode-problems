class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        bool flag=false;
        int xor_val=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0) flag=true;
            xor_val^=nums[i];
        }
        if(!flag) return 0;
        if(flag && xor_val==0) return n-1;
        return n; 
    }
};