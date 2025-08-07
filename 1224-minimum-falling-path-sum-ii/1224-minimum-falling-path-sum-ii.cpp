class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>t(n,vector<int>(n,0));
        for(int j=0;j<n;j++) t[0][j]=grid[0][j];
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int x1=INT_MAX;
                for(int k=0;k<n;k++){
                    if(j!=k) x1=min(x1,t[i-1][k]);
                }
                t[i][j]=grid[i][j]+x1;
            }
        }
        int mini=INT_MAX;
        for(int j=0;j<n;j++){
            mini=min(mini,t[n-1][j]);
        }
        return mini;
    }
};