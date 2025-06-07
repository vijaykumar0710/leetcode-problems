class Solution {
public:
    int helper(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        // Base case
        if (idx == 0) {
            if (amount % coins[0] == 0) return amount / coins[0];
            return 1e9; // represents INT_MAX-1
        }

        if (dp[idx][amount] != -1) return dp[idx][amount];

        int notTake = helper(idx - 1, amount, coins, dp);
        int take = 1e9;
        if (coins[idx] <= amount) {
            take = 1 + helper(idx, amount - coins[idx], coins, dp); // same idx because unlimited coins
        }

        return dp[idx][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = helper(n - 1, amount, coins, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};
