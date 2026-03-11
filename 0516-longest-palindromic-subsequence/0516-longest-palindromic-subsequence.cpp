class Solution {
public:
int dp[1001][1001];
int f(int i,int j,int n,string &s,string &t){
    if(i>=n || j>=n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int op1=0,op2=0,op3=0;
    if(s[i]==t[j]) op1=1+f(i+1,j+1,n,s,t);
    else{
       op2=f(i+1,j,n,s,t);
       op3=f(i,j+1,n,s,t);
    }
    return dp[i][j]=max({op1,op2,op3});
}
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string t=s;
        reverse(t.begin(),t.end());
        memset(dp,-1,sizeof(dp));
        return f(0,0,n,s,t);
    }
};