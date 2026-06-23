class Solution {
public:
    static const int MOD = 1e9 + 7;
    static const int MAXN = 2005;
    static const int MAXK = 2005;
    int N, K;
    int up[MAXN][MAXK];
    int down[MAXN][MAXK];
    int vis[MAXN];
    void solve(int len) {
        if (vis[len]) return;
        if (len == 2) {
            for (int x = 0; x < K; x++) {
                up[len][x] = x;
                down[len][x] = K - 1 - x;
            }
            vis[len] = 1;
            return;
        }
        solve(len - 1);
        long long prefUp[MAXK], prefDown[MAXK];
        prefUp[0] = up[len - 1][0];
        prefDown[0] = down[len - 1][0];
        for (int i = 1; i < K; i++) {
            prefUp[i] = (prefUp[i - 1] + up[len - 1][i]) % MOD;
            prefDown[i] = (prefDown[i - 1] + down[len - 1][i]) % MOD;
        }
        long long totalUp = prefUp[K - 1];
        for (int x = 0; x < K; x++) {
            up[len][x] = 0;
            down[len][x] = 0;
            if (x > 0) {
                up[len][x] = prefDown[x - 1];
            }
            down[len][x] = (totalUp - prefUp[x] + MOD) % MOD;
        }
        vis[len] = 1;
    }
    int zigZagArrays(int n, int l, int r) {
        N = n;
        K = r - l + 1;
        if (n == 1) return K;
        for (int i = 0; i <= N; i++) {
            vis[i] = 0;
            for (int j = 0; j < K; j++) {
                up[i][j] = 0;
                down[i][j] = 0;
            }
        }
        solve(N);
        long long ans = 0;
        for (int x = 0; x < K; x++) {
            ans += up[N][x];
            ans %= MOD;

            ans += down[N][x];
            ans %= MOD;
        }
        return ans;
    }
};