class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;
    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& vis,vector<vector<int>>& h) {
        while (!q.empty()) {
            int r = q.front().first,c = q.front().second; q.pop();
            for (auto& dir : directions) {
                int n_r = r + dir[0], n_c = c + dir[1];
                if (n_r < 0 || n_c < 0 || n_r >= m || n_c >= n || vis[n_r][n_c] || h[n_r][n_c] < h[r][c]) continue;
                vis[n_r][n_c] = true;
                q.push({n_r, n_c});
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        m = h.size(), n = h[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));
        queue<pair<int, int>> qa, qp;

        for (int j = 0; j < n; j++) pac[0][j] = true, qp.push({0, j});
        for (int i = 0; i < m; i++) pac[i][0] = true, qp.push({i, 0});
        for (int j = 0; j < n; j++) atl[m - 1][j] = true, qa.push({m - 1, j});
        for (int i = 0; i < m; i++) atl[i][n - 1] = true, qa.push({i, n - 1});

        bfs(qa, atl, h);
        bfs(qp, pac, h);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (atl[i][j] && pac[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }
};