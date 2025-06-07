class Solution {
public:
int solve(vector<int>&prices,int idx,int buy,int n,vector<vector<int>>&t){
    if(idx==n) return 0;
   if(t[idx][buy]!=-1) return t[idx][buy];
    long profit=0;
    if(buy){
        profit=max(-prices[idx]+solve(prices,idx+1,0,n,t),solve(prices,idx+1,1,n,t));
    }else{
        profit=max(prices[idx]+solve(prices,idx+1,1,n,t),solve(prices,idx+1,0,n,t));
    }
    return t[idx][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>t(n+1,vector<int>(2,-1));
        return solve(prices,0,1,n,t);
    }
};