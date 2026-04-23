class Solution {
public:
    vector<vector<int>> directions = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
    int st_r, st_c;
    int en_r, en_c;
    int m, n,cnt;
    void solve(int r, int c, int& res, vector<vector<int>>& grid,int &count) {
        if (r == en_r && c == en_c) {
           if(cnt==count) res++;
        }
        for (auto dir : directions) {
            int n_r = r + dir[0], n_c = c + dir[1];
            if (n_r >= 0 && n_r < m && n_c >= 0 && n_c < n &&
                (grid[n_r][n_c] == 0 || grid[n_r][n_c] == 2)) {
                int temp = grid[n_r][n_c];
                count++;
                grid[n_r][n_c] = 3;
                solve(n_r, n_c, res, grid,count);
                grid[n_r][n_c] = temp;
                count--;
            }
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int res = 0;
        m = grid.size();
        n = grid[0].size();
        cnt=0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    st_r = i, st_c = j;
                if (grid[i][j] == 2)
                    en_r = i, en_c = j;
                if(grid[i][j]!=-1) cnt++;
            }
        }
        int count=1;
        solve(st_r, st_c, res, grid,count);
        return res;
    }
};