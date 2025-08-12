const int M=1e9+7;
typedef long long ll;
class Solution {
public:
int dp[301][301];
int f(int i,ll sum,int n,int x){ 
    if(sum<0) return 0;
    if(sum==0) return 1;
    if(i>n) return 0;
    if(dp[i][sum]!=-1) return dp[i][sum];
    int skip=f(i+1,sum,n,x);
    ll new_sum=sum-(pow(i,x));
    int take=f(i+1,new_sum,n,x);
    return dp[i][sum]=(take+skip)%M;
}
    int numberOfWays(int n, int x) {
        memset(dp,-1,sizeof(dp));
     return f(1,n,n,x);   
    }
};