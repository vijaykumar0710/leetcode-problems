class Solution {
public:
int t[5001][2];
int f(int idx,int buy,vector<int>&prices,int n){
    if(idx>=n) return 0;
    if(t[idx][buy]!=-1) return t[idx][buy];
    long long profit=0;
    if(buy){
        profit=max(-prices[idx]+f(idx+1,0,prices,n),f(idx+1,1,prices,n));
    }else{
        profit=max(prices[idx]+f(idx+2,1,prices,n),f(idx+1,0,prices,n));
    }
    return t[idx][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        memset(t,-1,sizeof(t));
        return f(0,1,prices,n);
    }
};