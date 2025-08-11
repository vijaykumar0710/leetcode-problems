class Solution {
public:
int n,m;
int dp[1001][1001];
int f(string &s,string &t,int i,int j){
    if(j>=m) return 1;
    if(i>=n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ways=0;
    ways+=f(s,t,i+1,j);
    if(s[i]==t[j]) ways+=f(s,t,i+1,j+1);
    return dp[i][j]=ways;
}
    int numDistinct(string s, string t) {
        n=s.size();
        m=t.size();
        memset(dp,-1,sizeof(dp));
        return f(s,t,0,0);        
    }
};