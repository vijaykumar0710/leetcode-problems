class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int m=s.size();
        string st=s;
        reverse(st.begin(),st.end());
        vector<int>dp(m+1,0);
        for(int i=1;i<=m;i++){
            vector<int>t(m+1,0);
            for(int j=1;j<=m;j++){
                if(s[i-1]==st[j-1]) t[j]=1+dp[j-1];
                else t[j]=max(t[j-1],dp[j]);
            }
            dp=t;
        }
        return dp[m];
    }
};