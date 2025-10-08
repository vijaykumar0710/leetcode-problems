class Solution {
public:
    int longestPalindrome(string word1, string word2) {
      string s=word1+word2;
      int n=s.size();
        vector<vector<int>>t(n,vector<int>(n,0));
        for(int i=0;i<n;i++) t[i][i]=1;
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=len+i-1;
                if(s[i]==s[j]) t[i][j]=2+t[i+1][j-1];
                else t[i][j]=max(t[i+1][j],t[i][j-1]);
            }
        }
      int res=0;
      for(int i=0;i<word1.size();i++){
        for(int j=word1.size();j<n;j++){
            if(s[i]==s[j]) res=max(res,t[i][j]);
        }
      }
      return res;
    }
};