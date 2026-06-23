class Solution {
    int MOD = 1e9 + 7;
    int N,L,R;
    vector<int> memo;
    int dfs(int idx, int val, int dir) {
        if (idx == N) return 1;
        int memo_idx = (idx * (R + 1) + val) * 2 + dir;
        if (memo[memo_idx] != -1) return memo[memo_idx];
        long long ways = 0;
        if (dir == 1) { 
            if (val < R) {
                ways = (dfs(idx + 1, val + 1, 0) + dfs(idx, val + 1, 1)) % MOD;
            }
        } 
        else { 
            if (val > L) {
                ways = (dfs(idx + 1, val - 1, 1) + dfs(idx, val - 1, 0)) % MOD;
            }
        }
        return memo[memo_idx] = ways;
    }
public:
    int zigZagArrays(int n, int l, int r) {
        N = n;
        L=l,R=r;
        if (n == 1) return  r - l + 1;
        memo.assign((N + 1) * (r + 1) * 2, -1);
        long long total_ways = 0;
        for (int first_val = l; first_val <= r; first_val++) {
            total_ways = (total_ways + dfs(1, first_val, 1)) % MOD;
            total_ways = (total_ways + dfs(1, first_val, 0)) % MOD;
        }
        return total_ways;
    }
};