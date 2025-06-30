class Solution {
public:
    int n;
    vector<int> prefix;
    int t[31][31][31];
    int rangeSum(int i, int j) { return prefix[j + 1] - prefix[i]; }
    int solve(int i, int j, int k, int piles) {
        if ((j - i + 1 - piles) % (k - 1) != 0)
            return INT_MAX;
        if (i == j)
            return (piles == 1) ? 0 : INT_MAX;
        if(t[i][j][piles]!=-1) return t[i][j][piles];
        int res = INT_MAX;
        if (piles == 1) {
            int temp = solve(i, j, k, k);
            if (temp != INT_MAX)
                res = temp + rangeSum(i, j);
        } else {
            for (int p = i; p < j; p += (k - 1)) {
                int left = solve(i, p, k, 1);
                int right = solve(p + 1, j, k, piles - 1);
                if (left != INT_MAX && right != INT_MAX)
                    res = min(res, left + right);
            }
        }
        return t[i][j][piles]=res;
    }
    int mergeStones(vector<int>& stones, int k) {
        n = stones.size();
        prefix.resize(n+1, 0);
        for (int i = 0; i < n; i++) 
            prefix[i+1] = prefix[i] + stones[i];
            if ((n - 1) % (k - 1) != 0)
                return -1;
            int i = 0, j = n - 1;
            memset(t,-1,sizeof(t));
            return solve(i, j, k, 1);
        }
    };