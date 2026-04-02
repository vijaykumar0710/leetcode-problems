class Solution {
public:
const int INF = -1e9; 
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        vector<vector<vector<int>>> t(m, vector<vector<int>>(n, vector<int>(3, INF)));
        t[0][0][0] = coins[0][0]; 
        if (coins[0][0] < 0) t[0][0][1] = 0; 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue; 
                for (int k = 0; k < 3; k++) {
                    int maxi1 = INF;
                    if (i > 0) maxi1 = max(maxi1, t[i-1][j][k]);
                    if (j > 0) maxi1 = max(maxi1, t[i][j-1][k]);
                    if (maxi1 != INF) {
                        t[i][j][k] = max(t[i][j][k], maxi1 + coins[i][j]);
                    }
                    if (k > 0 && coins[i][j] < 0) {
                        int maxi2 = INF;
                        if (i > 0) maxi2 = max(maxi2, t[i-1][j][k-1]);
                        if (j > 0) maxi2 = max(maxi2, t[i][j-1][k-1]);
                        if (maxi2 != INF) {
                            t[i][j][k] = max(t[i][j][k], maxi2); 
                        }
                    }
                }
            }
        }
        return max({t[m-1][n-1][0], t[m-1][n-1][1], t[m-1][n-1][2]});
    }
};