typedef long long ll;
class Solution {
public:
    int n;
    vector<ll> memo;
    vector<int> cost;

    // returns dp[i] = min cost to cover all windows ending <= i
    ll solve(int i) {
        if (i < 2) return 0;           // no windows to cover
        if (memo[i] != -1) return memo[i];

        ll best = LLONG_MAX / 4;
        // choose j = i
        best = min(best, (ll)cost[i] + solve(i - 1));
        // choose j = i-1
        best = min(best, (ll)cost[i - 1] + solve(i - 2));
        // choose j = i-2
        best = min(best, (ll)cost[i - 2] + solve(i - 3));

        return memo[i] = best;
    }

    long long minIncrementOperations(vector<int>& nums, int k) {
        n = nums.size();
        if (n < 3) return 0;          // no constraints when n < 3

        cost.assign(n, 0);
        for (int i = 0; i < n; ++i) cost[i] = max(0, k - nums[i]);

        memo.assign(n, -1);
        return solve(n - 1);
    }
};