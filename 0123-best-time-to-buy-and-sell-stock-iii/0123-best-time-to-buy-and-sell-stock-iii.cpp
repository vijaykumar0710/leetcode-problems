class Solution {
public:
int f(int idx,int buy,int tran,vector<int>&prices,int n,vector<vector<vector<int>>>&t){
    if(tran==0) return 0;
    if(idx==n) return 0;
    if(t[idx][buy][tran]!=-1) return t[idx][buy][tran];
    long long profit=0;
    if(buy){
        profit=max(-prices[idx]+f(idx+1,0,tran,prices,n,t),f(idx+1,1,tran,prices,n,t));
    }else{
        profit=max(prices[idx]+f(idx+1,1,tran-1,prices,n,t),f(idx+1,0,tran,prices,n,t));
    }
    return t[idx][buy][tran]=profit;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>t(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2,prices,n,t);
    }
};