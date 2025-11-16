class Solution {
public:
    string s;
    long long dp[20][2][2];
    long long f(int i, bool tight, bool started) {
        if (i == s.size()) 
            return started ? 1 : 0;

        if (!tight && dp[i][tight][started])
            return dp[i][tight][started];

        long long res = 0;
        int limit = tight ? (s[i] - '0') : 9;

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);
            bool nstart = started || (d != 0);

            if (!nstart) {
                res += f(i + 1, ntight, nstart);
            } else {
                if (d == 0) continue;
                res += f(i + 1, ntight, nstart);
            }
        }

     if(!tight) dp[i][tight][started] = res;
        return res;
    }

    long long countDistinct(long long n) {
        s = to_string(n);
        memset(dp, 0, sizeof(dp));
        return f(0, true, false);
    }
};
