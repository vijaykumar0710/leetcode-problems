class Solution {
public:
    int n;
    const long long INF = 1e18;
    vector<vector<long long>> dp;

    long long solve(int i, int freetime, vector<int>& cost, vector<int>& time) {
        if (i == n) {
            return freetime >= 0 ? 0 : INF;
        }

        if (dp[i][freetime + n] != -1) {
            return dp[i][freetime + n];
        }

        // Option 1: hire painter i
        int newFree = min(n, freetime + time[i]);
        long long hire = cost[i] + solve(i + 1, newFree, cost, time);

        // Option 2: self-paint
        long long self = solve(i + 1, freetime - 1, cost, time);

        return dp[i][freetime + n] = min(hire, self);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        dp.assign(n + 1, vector<long long>(2 * n + 1, -1));
        return solve(0, 0, cost, time);
    }
};
