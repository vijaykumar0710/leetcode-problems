class Solution {
public:
int m,n;
int dp[1001][1001];
int lcs(string& s1, string& s2,int i,int j){
    if(i>=m || j>=n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int res=INT_MIN;
    if(s1[i]==s2[j]) res=max(res,1+lcs(s1,s2,i+1,j+1));
    else res=max({res,lcs(s1,s2,i+1,j),lcs(s1,s2,i,j+1)});
    return dp[i][j]=res;
}
    int longestCommonSubsequence(string s1, string s2) {
        m=s1.length();
        n=s2.length();
        memset(dp,-1,sizeof(dp));
      return lcs(s1,s2,0,0);
    }
};