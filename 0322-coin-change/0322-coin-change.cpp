class Solution {
public:
int dp[13][10005];
int f(int i,int n,vector<int>&coins,int amount){
    if(i>=n){
        if(amount==0) return 0;
        return 1e9;
    }
    if(dp[i][amount]!=-1) return dp[i][amount];
    int op1=1e9;
    if(amount-coins[i]>=0) op1=1+f(i,n,coins,amount-coins[i]);
    int op2=f(i+1,n,coins,amount);
    return dp[i][amount]=min(op1,op2);
}
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int res=f(0,coins.size(),coins,amount);
        if(res==1e9) return -1;
        return res;
    }
};