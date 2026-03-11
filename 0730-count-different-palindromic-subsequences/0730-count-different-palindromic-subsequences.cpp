class Solution {
public:
const int M=1e9+7;
    int countPalindromicSubsequences(string s) {
        int n=s.size();
        vector<vector<int>>t(n,vector<int>(n,0));
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
               if(g==0) t[i][j]=1;
               else if(g==1) t[i][j]=2;
               else{
                 if(s[i]!=s[j]) t[i][j]=((t[i+1][j]%M+t[i][j-1]%M)%M-t[i+1][j-1]%M+M)%M;
                 else{
                    int l=i+1,r=j-1;
                    while(l<=j && s[l]!=s[i]) l++;
                    while(r>=i && s[r]!=s[j]) r--;
                    if(l==r) t[i][j]=(2*t[i+1][j-1]+1)%M;
                    else if(l==j && r==i) t[i][j]=(2*t[i+1][j-1]+2)%M;
                    else t[i][j]=(2*t[i+1][j-1]%M-t[l+1][r-1]%M+M)%M;
                 }
               }
            }
        }
        return t[0][n-1];
    }
};