class Solution {
public:
int dp[1001][1001];
int lcs(int i,int j,string &s1,string &s2,int m){
    if(i>=m || j>=m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]) return dp[i][j]=1+lcs(i+1,j+1,s1,s2,m);
    else return dp[i][j]=max(lcs(i+1,j,s1,s2,m),lcs(i,j+1,s1,s2,m));
}
    int longestPalindromeSubseq(string s) {
        int m=s.size();
        string s1=s;
        string s2=s;
        reverse(s2.begin(),s2.end());
        memset(dp,-1,sizeof(dp));
        return lcs(0,0,s1,s2,m);
    }
};