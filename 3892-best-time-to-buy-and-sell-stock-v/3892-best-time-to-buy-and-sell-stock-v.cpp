class Solution {
public:
long long t[1001][3][501];
long long f(int i,int state,int k,vector<int>&prices,int n){
if(i==n) return (state==0)?0:INT_MIN/2;
if(k==0) return (state==0)?0:INT_MIN/2;
if(t[i][state][k]!=-1) return t[i][state][k];
long long profit=0;
if(state==0){
    long long skip=f(i+1,0,k,prices,n);
    long long nT=-prices[i]+f(i+1,1,k,prices,n);
    long long sT=prices[i]+f(i+1,2,k,prices,n);
    profit=max({skip,nT,sT});
  }else if(state==1){
    profit=max(prices[i]+f(i+1,0,k-1,prices,n),f(i+1,1,k,prices,n));
  }else{
    profit=max(-prices[i]+f(i+1,0,k-1,prices,n),f(i+1,2,k,prices,n));
  }
  return t[i][state][k]=profit;
}
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        memset(t,-1,sizeof(t));
        return max(0LL,f(0,0,k,prices,n));
    }
};