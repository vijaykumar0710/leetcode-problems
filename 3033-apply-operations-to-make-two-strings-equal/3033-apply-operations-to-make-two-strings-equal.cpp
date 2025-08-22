class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        vector<int> pos;
        int n = s1.size();
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) pos.push_back(i);
        }
        if (pos.empty()) return 0;
        if (pos.size() % 2 == 1) return -1; // impossible

        int m = pos.size();
        const int INF = 1e9;
        vector<vector<int>> dp(m, vector<int>(m, 0));

        // length of interval (must be even)
        for (int len = 2; len <= m; len += 2) {
            for (int l = 0; l + len - 1 < m; l++) {
                int r = l + len - 1;
                dp[l][r] = INF;
                // try pairing pos[l] with some pos[k]
                for (int k = l + 1; k <= r; k += 2) {
                    int cost = min(x, pos[k] - pos[l]);
                    int left = (l + 1 <= k - 1) ? dp[l + 1][k - 1] : 0;
                    int right = (k + 1 <= r) ? dp[k + 1][r] : 0;
                    dp[l][r] = min(dp[l][r], left + cost + right);
                }
            }
        }
        return dp[0][m - 1];
    }
};