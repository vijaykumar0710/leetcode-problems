class Solution {
public:
int t[13][10001];
int f(int n,vector<int>& coins, int amount){
    if(n==0 && amount>0) return 1e9;
    if(amount==0) return 0;
    if(n==1){ 
        if(amount%coins[0]==0) return amount/coins[0];
         return 1e9;
    }
    if(t[n][amount]!=-1) return t[n][amount];
    int take=1e9;
    if(coins[n-1]<=amount){
        take=1+f(n,coins,amount-coins[n-1]);
    }
    int skip=f(n-1,coins,amount);
    return t[n][amount]=min(take ,skip);
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        memset(t,-1,sizeof(t));
        int ans=f(n,coins,amount);
        if(ans>=1e9) return -1;
        return ans;
    }
};