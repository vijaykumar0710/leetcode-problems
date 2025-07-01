class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1) return 0;
        vector<vector<int>> t(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1)
                    t[i][j] = -1;
            }
        }
        for (int j = 0; j < n; j++) {
            if (t[0][j] != -1)
                t[0][j] = 1;
            else
                break;
        }
        for (int i = 0; i < m; i++) {
            if (t[i][0] != -1)
                t[i][0] = 1;
            else
                break;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (t[i][j] != -1) {
                    int up=t[i-1][j];
                    int left=t[i][j-1];
                    if(up<0) up=0;
                    if(left<0) left=0;
                    t[i][j]=up+left;
                }
            }
        }
        return t[m - 1][n - 1];
    }
};