class Solution {
public:
    long long memo[1001][3][501]; 
    long long solve(int idx, int state, int k_rem, vector<int>& prices, int n) {
        if (idx == n) {
            return (state == 0) ? 0 : LLONG_MIN / 2; 
        }

        if (k_rem == 0) {
            return (state == 0) ? 0 : LLONG_MIN / 2;
        }

        if (memo[idx][state][k_rem] != -1) {
            return memo[idx][state][k_rem];
        }

        long long current_max_profit = 0;

        if (state == 0) {
            long long skip_today_profit = solve(idx + 1, 0, k_rem, prices, n);
            long long buy_normal_profit = -prices[idx] + solve(idx + 1, 1, k_rem, prices, n);
            long long sell_short_profit = prices[idx] + solve(idx + 1, 2, k_rem, prices, n);

            current_max_profit = max({skip_today_profit, buy_normal_profit, sell_short_profit});

        } else if (state == 1) {
            long long skip_today_profit = solve(idx + 1, 1, k_rem, prices, n);
            long long sell_profit = prices[idx] + solve(idx + 1, 0, k_rem - 1, prices, n);
            
            current_max_profit = max(skip_today_profit, sell_profit);

        } else {
            long long skip_today_profit = solve(idx + 1, 2, k_rem, prices, n);
            long long buy_back_profit = -prices[idx] + solve(idx + 1, 0, k_rem - 1, prices, n);

            current_max_profit = max(skip_today_profit, buy_back_profit);
        }

        return memo[idx][state][k_rem] = current_max_profit;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        if (n < 2) {
            return 0;
        }
        memset(memo, -1, sizeof(memo));
        long long final_profit = solve(0, 0, k, prices, n);
        return max(0LL, final_profit);
    }
};