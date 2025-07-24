class Solution {
public:
int t[501][501];
int f(int m,int n,string &s1,string &s2){
    if(m==0) return n;
    if(n==0) return m;
    if(t[m][n]!=-1) return t[m][n];
     if(s1[m-1]==s2[n-1]) t[m][n]=f(m-1,n-1,s1,s2);
     else t[m][n]=1+min(f(m-1,n,s1,s2),f(m,n-1,s1,s2));
     return t[m][n];
}
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        memset(t,-1,sizeof(t));
        return f(m,n,word1,word2);
    }
};