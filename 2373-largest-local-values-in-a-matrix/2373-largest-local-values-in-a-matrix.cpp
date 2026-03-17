class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& g) {
        int n=g.size();
        vector<vector<int>>t(n-2,vector<int>(n-2));
        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=n-3;j++){
                t[i][j]=max({g[i][j],g[i][j+1],g[i][j+2],g[i+1][j],g[i+1][j+1],g[i+1][j+2],g[i+2][j],g[i+2][j+1],g[i+2][j+2]});
            }
        }
        return t;
    }
};