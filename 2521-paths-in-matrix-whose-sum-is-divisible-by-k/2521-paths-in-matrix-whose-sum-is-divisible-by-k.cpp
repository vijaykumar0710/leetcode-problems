const int M = 1e9+7;
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> t(m, vector<vector<int>>(n, vector<int>(k, 0)));
        t[0][0][grid[0][0]%k]++;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int r=0;r<k;r++){
                    int new_r=(r+grid[i][j])%k;
                    if(i>0 && t[i-1][j][r]>0) t[i][j][new_r]=(t[i][j][new_r]+t[i-1][j][r])%M;
                    if(j>0 && t[i][j-1][r]>0) t[i][j][new_r]=(t[i][j][new_r]+t[i][j-1][r])%M;
                }
            }
        }
        return t[m-1][n-1][0];
    }
};