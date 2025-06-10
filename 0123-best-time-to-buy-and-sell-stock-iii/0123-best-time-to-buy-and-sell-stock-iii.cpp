class Solution {
public:
int t[100000+1][2][3];
int f(int idx,int buy,int tran,vector<int>&prices,int n){
    if(tran==0 || idx==n) return 0;
    if(t[idx][buy][tran]!=-1) return t[idx][buy][tran];
    long long profit=0;
    if(buy){
        profit=max(-prices[idx]+f(idx+1,0,tran,prices,n),f(idx+1,1,tran,prices,n));
    }else{
        profit=max(prices[idx]+f(idx+1,1,tran-1,prices,n),f(idx+1,0,tran,prices,n));
    }
    return t[idx][buy][tran]=profit;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        memset(t,-1,sizeof(t));
        return f(0,1,2,prices,n);
    }
};