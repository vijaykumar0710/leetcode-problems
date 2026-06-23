class Solution {
    int MOD = 1e9 + 7;
    int K;
    int N;
    vector<int> t;
    int f(int idx, int val, int dir) {
        if (idx == N) return 1;
        int memo_idx = (idx * (K + 1) + val) * 2 + dir;
        if (t[memo_idx] != -1) {
            return t[memo_idx];
        }
        long long ways = 0;
            if (dir == 1) { 
            if (val < K) {
                ways = (f(idx + 1, val + 1, 0) + f(idx, val + 1, 1)) % MOD;
            }
        } 
        else { 
            if (val > 1) {
                ways = (f(idx + 1, val - 1, 1) + f(idx, val - 1, 0)) % MOD;
            }
        }
        return t[memo_idx] = ways;
    }
public:
    int zigZagArrays(int n, int l, int r) {
        K = r - l + 1;
        N = n;
        if (n == 1) return K;
        t.assign((N + 1) * (K + 1) * 2, -1);
        long long total_ways = 0;
        for (int first_val = 1; first_val <= K; first_val++) {
            total_ways = (total_ways + f(1, first_val, 1)) % MOD;
            total_ways = (total_ways + f(1, first_val, 0)) % MOD;
        }
        return total_ways;
    }
};