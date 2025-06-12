class Solution {
public:
    int n;
    const long long INF = INT_MAX;

    long long solve(int i, int freetime, vector<int>& cost, vector<int>& time, vector<vector<long long>>&dp) {
        if (i == n) {
            return freetime >= 0 ? 0 : INF;
        }

        if (dp[i][freetime + n] != -1) {
            return dp[i][freetime + n];
        }

        // Option 1: hire painter i
        int newFree = min(n, freetime + time[i]);
        long long hire = cost[i] + solve(i + 1, newFree, cost, time,dp);

        // Option 2: self-paint
        long long self = solve(i + 1, freetime - 1, cost, time,dp);

        return dp[i][freetime + n] = min(hire, self);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
          vector<vector<long long>> dp(n + 1, vector<long long>(2 * n + 1, -1));
        return solve(0, 0, cost, time,dp);
    }
};
