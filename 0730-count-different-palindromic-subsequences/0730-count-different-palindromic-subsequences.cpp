class Solution {
public:
const int M=1e9+7;
    int countPalindromicSubsequences(string s) {
        int n=s.size();
        vector<vector<long long>>t(n,vector<long long>(n,0));
        for(int i=0;i<n;i++) t[i][i]=1;
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=len+i-1;
                if(s[i]!=s[j]) t[i][j]=(t[i+1][j]+t[i][j-1]-t[i+1][j-1]+M)%M;
                else{
                    int l=i+1,r=j-1;
                    while(l<=j && s[l]!=s[i]) l++;
                    while(r>=i && s[r]!=s[j]) r--;
                    if(l==j && r==i) t[i][j]=(2*t[i+1][j-1]+2)%M;
                    else if(l==r) t[i][j]=(2*t[i+1][j-1]+1)%M;
                    else t[i][j]=(2*t[i+1][j-1]-t[l+1][r-1]+M)%M;
                }
            }
        }
        return t[0][n-1];
    }
};