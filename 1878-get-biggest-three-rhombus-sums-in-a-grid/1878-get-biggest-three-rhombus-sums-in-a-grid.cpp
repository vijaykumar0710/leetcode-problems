class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int> sums;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sums.insert(grid[i][j]);
                int maxRadius = min({i, j, m - 1 - i, n - 1 - j});
                for (int k = 1; k <= maxRadius; k++) {
                    int sum = 0;
                    int x = i - k, y = j;
                    for (int d = 0; d < k; d++) {
                        sum += grid[x + d][y + d];
                    }
                    for (int d = 0; d < k; d++) {
                        sum += grid[i + d][j + k - d];
                    }
                    for (int d = 0; d < k; d++) {
                        sum += grid[i + k - d][j - d];
                    }
                    for (int d = 0; d < k; d++) {
                        sum += grid[i - d][j - k + d];
                    }
                    sums.insert(sum);
                }
            }
        }
        vector<int> ans;
        for (auto it = sums.rbegin(); it != sums.rend() && ans.size() < 3;
             it++) {
            ans.push_back(*it);
        }
        return ans;
    }
};