int dp[2005][2005][3];
const int M = 1e9 + 7;
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int N = n, L = l, R = r;
        memset(dp, 0, sizeof(dp));
        for (int num = L; num <= R; num++) {
            dp[N][num][0] = 1;
            dp[N][num][1] = 1;
        }
        for (int len = N - 1; len >= 1; len--) {
            dp[len][R][1] = 0;
            for (int num = R - 1; num >= L; num--) {
                dp[len][num][1] =
                    (dp[len + 1][num + 1][0] + dp[len][num + 1][1]) % M;
            }
            dp[len][L][0] = 0;
            for (int num = L + 1; num <= R; num++) {
                dp[len][num][0] =(dp[len + 1][num - 1][1] + dp[len][num - 1][0]) % M;
            }
        }
        int res = 0;
        for (int i = L; i <= R; i++) {
            res = (res + dp[1][i][1]) % M;
            res = (res + dp[1][i][0]) % M;
        }
        return res;
    }
};