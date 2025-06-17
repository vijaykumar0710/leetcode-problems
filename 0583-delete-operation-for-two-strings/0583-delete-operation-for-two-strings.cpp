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
    int minDistance(string s1, string s2) {
        int m=s1.size(),n=s2.size();
        vector<vector<int>>t(m+1,vector<int>(n+1,-1));
        return helper(s1,s2,m,n,t);
    }
};