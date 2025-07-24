class Solution {
public:
int t[1001][1001];
int f(int m,int n,string &s1,string &s2){
   if(m==0 || n==0) return 0;
   if(t[m][n]!=-1) return t[m][n];
   if(s1[m-1]==s2[n-1]){
    return t[m][n]=1+f(m-1,n-1,s1,s2);
   }
   return t[m][n]=max(f(m,n-1,s1,s2),f(m-1,n,s1,s2));
}
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        memset(t,-1,sizeof(t));
        return f(m,n,text1,text2);
    }
};