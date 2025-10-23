class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if ((n - 1) % (K - 1) != 0) return -1;

        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + stones[i];
        auto sum = [&](int i, int j) { return prefix[j + 1] - prefix[i]; };

        const int INF = 1e9;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(K + 1, INF)));

        for (int i = 0; i < n; i++) dp[i][i][1] = 0;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                for (int m = 2; m <= K; m++) {
                    for (int mid = i; mid < j; mid += K - 1) {  // optimization: skip redundant mid
                        dp[i][j][m] = min(dp[i][j][m], dp[i][mid][1] + dp[mid + 1][j][m - 1]);
                    }
                }
                if (dp[i][j][K] < INF)
                    dp[i][j][1] = dp[i][j][K] + sum(i, j);
            }
        }

        return dp[0][n - 1][1];
    }
};