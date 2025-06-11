class Solution {
public:
int t[1001][1001];
int lcs(string &s1,string &s2,int m,int n){
    if(m==0 || n==0) return 0;
    if(t[m][n]!=-1) return t[m][n];
    if(s1[m-1]==s2[n-1]){
        t[m][n]=1+lcs(s1,s2,m-1,n-1);
    }
    else  t[m][n]=max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
    return t[m][n];
}
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size(),n2=text2.size();
        memset(t,-1,sizeof(t));
        return lcs(text1,text2,n1,n2);
    }
};