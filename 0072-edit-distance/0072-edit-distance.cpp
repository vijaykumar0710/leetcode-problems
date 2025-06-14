class Solution {
public:
int solve(string &word1,string &word2,int m,int n,vector<vector<int>>&t){
    if(m==0) return n;
    if(n==0) return m;
    if(t[m][n]!=-1) return t[m][n];
    if(word1[m-1]==word2[n-1]) 
       return t[m][n]=solve(word1,word2,m-1,n-1,t);
    else{
        return t[m][n]=1+min({solve(word1,word2,m-1,n-1,t),solve(word1,word2,m-1,n,t),solve(word1,word2,m,n-1,t)});
    }
}
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>>t(m+1,vector<int>(n+1,-1));
        return solve(word1,word2,m,n,t);
    }
};