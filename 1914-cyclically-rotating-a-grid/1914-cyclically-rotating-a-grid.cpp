class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        for (int d = 0; d < min(m, n) / 2; d++) {
            vector<int> vec;
            int top = d;
            int bottom = m - 1 - d;
            int left = d;
            int right = n - 1 - d;
            for (int i = top; i < bottom; i++)
                vec.push_back(grid[i][left]);
            for (int j = left; j < right; j++)
                vec.push_back(grid[bottom][j]);
            for (int i = bottom; i > top; i--)
                vec.push_back(grid[i][right]);
            for (int j = right; j > left; j--)
                vec.push_back(grid[top][j]);
            int sz = vec.size();
            vector<int> res(sz);
            for (int pt = 0; pt < sz; pt++) {
                res[(pt + k) % sz] = vec[pt];
            }
            int it = 0;
            for (int i = top; i < bottom; i++)
                grid[i][left] = res[it++];
            for (int j = left; j < right; j++)
                grid[bottom][j] = res[it++];
            for (int i = bottom; i > top; i--)
                grid[i][right] = res[it++];
            for (int j = right; j > left; j--)
                grid[top][j] = res[it++];
        }
        return grid;
    }
};