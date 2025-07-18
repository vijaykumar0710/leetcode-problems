class Solution {
public:
int getMask(int val) {
        int mask = 0;
        while (val > 0) {
            int d = val % 10;
            if ((mask >> d) & 1) return -1;
            mask |= (1 << d);
            val /= 10;
        }
        return mask;
    }
    void dfs(int u, vector<vector<int>>& tree, vector<int>& vals, vector<int>& masks,
             vector<unordered_map<int, int>>& dp, long long &ans) {
        
        if (masks[u] != -1) {
            dp[u][masks[u]] = vals[u];
        }

        for (int v : tree[u]) {
            dfs(v, tree, vals, masks, dp, ans);

            unordered_map<int, int> new_dp = dp[u];
            for (auto &[mask1, sum1] : dp[u]) {
                for (auto &[mask2, sum2] : dp[v]) {
                    if ((mask1 & mask2) == 0) {
                        int new_mask = mask1 | mask2;
                        new_dp[new_mask] = max(new_dp[new_mask], sum1 + sum2);
                    }
                }
            }

            for (auto &[mask2, sum2] : dp[v]) {
                new_dp[mask2] = max(new_dp[mask2], sum2);
            }

            dp[u] = move(new_dp);
        }

        int best = 0;
        for (auto &[mask, sum] : dp[u]) {
            best = max(best, sum);
        }
        ans = (ans + best) % 1000000007;
    }

    int goodSubtreeSum(vector<int>& vals, vector<int>& par) {
      int n = vals.size();
        vector<vector<int>> tree(n);
        vector<int> masks(n);

        for (int i = 1; i < n; ++i) {
            tree[par[i]].push_back(i);
        }

        for (int i = 0; i < n; ++i) {
            masks[i] = getMask(vals[i]);
        }

        vector<unordered_map<int, int>> dp(n);
        long long ans = 0;
        dfs(0, tree, vals, masks, dp, ans);

        return ans;
    }
};