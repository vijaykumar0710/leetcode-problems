class Solution {
public:
int helper(string &s1,string &s2,int m,int n,vector<vector<int>>&t){
      if(m==0) return n;
      if(n==0) return m;
      
      if(t[m][n]!=-1) return t[m][n];
      if(s1[m-1]==s2[n-1]){
          return t[m][n]=helper(s1,s2,m-1,n-1,t);
      }else{
          return t[m][n]=1+min({helper(s1,s2,m-1,n,t),helper(s1,s2,m,n-1,t)});
      }
  }
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>>t(m+1,vector<int>(n+1));
        for(int i=0;i<=m;i++)
           t[i][0]=i;
         for(int j=0;j<=n;j++)
           t[0][j]=j;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    t[i][j]=t[i-1][j-1];
                }
                else{
                   t[i][j]=1+min(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[m][n];
    }
};