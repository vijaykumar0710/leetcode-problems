class Solution {
public:
    struct Node {
        long long cnt;
        long long sum;
    };
    string s;
    Node dp[20][11][11][2][2];
    bool vis[20][11][11][2][2];
    Node f(int idx, int p2, int p1, int tight, int started) {
        if (idx == s.size()) return {1, 0};
        if (vis[idx][p2 + 1][p1 + 1][tight][started])
            return dp[idx][p2 + 1][p1 + 1][tight][started];
        vis[idx][p2 + 1][p1 + 1][tight][started] = true;
        int limit = tight ? s[idx] - '0' : 9;
        Node ans = {0, 0};
        for (int d = 0; d <= limit; d++) {
            int newTight = tight && (d == limit);
            if (!started && d == 0) {
                Node child = f(idx + 1, -1, -1, newTight, 0);
                ans.cnt += child.cnt;
                ans.sum += child.sum;
            } else {
                Node child = f(idx + 1, p1, d, newTight, 1);
                int add = 0;
                if (p2 != -1 && p1 != -1) {
                    if ((p2 < p1 && p1 > d) || (p2 > p1 && p1 < d)) {
                        add = 1;
                    }
                }
                ans.cnt += child.cnt;
                ans.sum += child.sum + add * child.cnt;
            }
        }
        return dp[idx][p2 + 1][p1 + 1][tight][started] = ans;
    }
    long long solve(long long n) {
        if (n <= 0) return 0;
        s = to_string(n);
        memset(vis, false, sizeof(vis));
        return f(0, -1, -1, 1, 0).sum;
    }
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};