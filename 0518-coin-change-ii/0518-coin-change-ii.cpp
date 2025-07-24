class Solution {
public:
typedef unsigned long long ll;
int t[301][5001];
int f(int n,int amount,vector<int>&coins){
    if(amount==0) return 1;
    if(n<=0) return 0;
    if(t[n][amount]!=-1) return t[n][amount];
    ll take=0;
    if(coins[n-1]<=amount){
        take=f(n,amount-coins[n-1],coins);
    }
    ll skip=f(n-1,amount,coins);
    return t[n][amount]=(ll)take+skip;
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        memset(t,-1,sizeof(t));
        return f(n,amount,coins);
    }
};