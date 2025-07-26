class Solution {
public:
int f(string &s1,string &s2){
    int n=s1.size();
    vector<vector<int>>t(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1])
                t[i][j]=1+t[i-1][j-1];
            else t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    return t[n][n];
}
    int minInsertions(string s) {
        int n=s.size();
        string rev=s;
        reverse(rev.begin(),rev.end());
        return n-f(s,rev);
    }
};