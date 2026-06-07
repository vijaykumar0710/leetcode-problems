class Solution {
public:
    const long long NEG = -1e18;
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, NEG));
        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }
        long long answer = NEG;
        for (int k = 1; k <= m; k++) {
            deque<int> dq;
            for (int i = 1; i <= n; i++) {
                dp[k][i] = dp[k][i - 1];
                int addIndex = i - l;
                if (addIndex >= 0){
                    while (!dq.empty() && (dp[k - 1][dq.back()] - prefix[dq.back()]) <= (dp[k - 1][addIndex] - prefix[addIndex])) {
                        dq.pop_back();
                    }
                    dq.push_back(addIndex);
                }
                int leftLimit = i - r;
                while (!dq.empty() && dq.front() < leftLimit) {
                    dq.pop_front();
                }
                if (!dq.empty()) {
                    int bestJ = dq.front();
                    dp[k][i] = max(
                        dp[k][i],
                        prefix[i] + dp[k - 1][bestJ] - prefix[bestJ]
                    );
                }
            }
            answer = max(answer, dp[k][n]);
        }
        return answer;
    }
};