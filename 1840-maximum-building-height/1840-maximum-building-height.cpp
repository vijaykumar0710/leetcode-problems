class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& rest) {
        rest.push_back({1, 0});
        sort(rest.begin(), rest.end());
        int m=rest.size();
        if (rest[m - 1][0] != n) {
            rest.push_back({n, n - 1});
            m++;
        }
        for (int i = 1; i < m; i++) {
            int d = rest[i][0] - rest[i - 1][0];
            rest[i][1] = min(rest[i][1], rest[i - 1][1] + d);
        }
        for (int i = m - 2; i >= 0; i--) {
            int d = rest[i+1][0] - rest[i][0];
            rest[i][1] = min(rest[i][1], rest[i + 1][1] + d);
        }
        int res = 0;
        for (int i = 1; i < m; i++) {
            int id1 = rest[i - 1][0], h1 = rest[i - 1][1];
            int id2 = rest[i][0], h2 = rest[i][1];
            int max_h = (h1 + h2 + (id2 - id1)) / 2;
            res = max(res, max_h);
        }
        return res;
    }
};