class Solution {
public:
    vector<vector<int>> change(const vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> t(n + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i <= n; i++) t[i][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                if (coins[i - 1] <= j) {
                    t[i][j] = t[i][j - coins[i - 1]] + t[i - 1][j];
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        return t;
    }

    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        vector<int> candidates;
        for (int i = 0; i < n; i++) {
            if (numWays[i] != 0) candidates.push_back(i + 1);
        }
        int m = candidates.size();
        vector<int> best;
        for (int mask = 1; mask < (1 << m); mask++) {
            vector<int> coins;
            for (int i = 0; i < m; i++) {
                if (mask & (1 << i)) {
                    coins.push_back(candidates[i]);
                }
            }
            auto t = change(coins, n);
            bool flag = true;
            for (int j = 1; j <= n; j++) {
                if (t[coins.size()][j] != numWays[j - 1]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                if (best.empty() || coins.size() < best.size()) {
                    best = coins;
                }
            }
        }
        return best;
    }
};
