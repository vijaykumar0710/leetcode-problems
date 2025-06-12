class Solution {
public:
const int M=1e9+7;
int dfs(vector<int>&nums,int mask,int last,int n,vector<vector<int>>&dp){
    if(mask==(1<<n)-1) return 1;
    if(dp[mask][last]!=-1) return dp[mask][last];
    int ans=0;
    for(int i=0;i<n;i++){
        if(!(mask&(1<<i))){
            if(nums[i]%nums[last]==0 || nums[last]%nums[i]==0){
                ans=(ans+dfs(nums,mask|(1<<i),i,n,dp))%M;
            }
        }
    }
    return dp[mask][last]=ans;
}
    int specialPerm(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(1<<n,vector<int>(n,-1));
        int res=0;
        for(int i=0;i<n;i++){
            res=(res+dfs(nums,1<<i,i,n,dp))%M;
        }
        return res;
    }
};