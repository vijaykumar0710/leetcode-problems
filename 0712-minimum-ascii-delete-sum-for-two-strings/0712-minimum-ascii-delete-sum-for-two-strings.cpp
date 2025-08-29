class Solution {
public:
int n1,n2;
int t[1001][1001];
int f(int i,int j,string &s1, string &s2){
    if(i>=n1 && j>=n2) return 0;
    if(t[i][j]!=-1) return t[i][j];
    if(j>=n2) return t[i][j]=s1[i]+f(i+1,j,s1,s2);
    if(i>=n1) return t[i][j]=s2[j]+f(i,j+1,s1,s2);
    if(s1[i]==s2[j]) return t[i][j]=f(i+1,j+1,s1,s2);
    int op1=s1[i]+f(i+1,j,s1,s2);
    int op2=s2[j]+f(i,j+1,s1,s2);
    return t[i][j]=min(op1,op2);
}
    int minimumDeleteSum(string s1, string s2) {
        n1=s1.size(),n2=s2.size();
        memset(t,-1,sizeof(t));
        return f(0,0,s1,s2);
    }
};