class Solution {
public:
    using ll = long long;
    const ll NEG = -4e18;
    struct SegmentTree {
        int n;
        vector<ll> tree;
        ll NEG;
        SegmentTree() {}
        SegmentTree(int size, ll neg) {
            init(size, neg);
        }
        void init(int size, ll neg) {
            n = size;
            NEG = neg;
            tree.assign(4 * n, NEG);
        }
        void update(int node, int start, int end, int idx, ll val) {
            if (start == end) {
                tree[node] = val;
                return;
            }
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
        void update(int idx, ll val) {
            update(1, 0, n - 1, idx, val);
        }
        ll query(int node, int start, int end, int l, int r) {
            if (r < start || end < l) {
                return NEG;
            }
            if (l <= start && end <= r) {
                return tree[node];
            }
            int mid = (start + end) / 2;
            return max(
                query(2 * node, start, mid, l, r),
                query(2 * node + 1, mid + 1, end, l, r)
            );
        }
        ll query(int l, int r) {
            if (l > r) return NEG;
            return query(1, 0, n - 1, l, r);
        }
    };
    int n, L, R, M;
    vector<ll> prefix;
    vector<vector<ll>> dp;
    vector<vector<int>> vis;
    vector<SegmentTree> seg;
    vector<vector<int>> nxt;
    int findNext(int k, int x) {
        if (x > n) return x;
        if (nxt[k][x] == x) return x;
        return nxt[k][x] = findNext(k, nxt[k][x]);
    }
    void markComputed(int k, int i, ll ans) {
        vis[k][i] = 1;
        dp[k][i] = ans;
        if (ans <= NEG / 2) {
            seg[k].update(i, NEG);
        } else {
            seg[k].update(i, prefix[i] + ans);
        }
        nxt[k][i] = findNext(k, i + 1);
    }
    void ensureBuilt(int k, int l, int r) {
        if (k == 0) return;
        int x = findNext(k, l);
        while (x <= r) {
            dfs(x, k);
            x = findNext(k, x);
        }
    }
    ll dfs(int i, int k) {
        if (k == 0) return 0;
        if (i > n) return NEG;
        if (vis[k][i]) return dp[k][i];
        ll ans = NEG;
        if (i >= n || n - i < 1LL * k * L) {
            ans = NEG;
        } else {
            ans = dfs(i + 1, k);
            int left = i + L;
            int right = min(n, i + R);
            if (left <= right) {
                ensureBuilt(k - 1, left, right);
                ll best = seg[k - 1].query(left, right);
                if (best > NEG / 2) {
                    ans = max(ans, best - prefix[i]);
                }
            }
        }
        markComputed(k, i, ans);
        return ans;
    }
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        n = nums.size();
        M = m;
        L = l;
        R = r;
        prefix.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        dp.assign(M + 1, vector<ll>(n + 1, NEG));
        vis.assign(M + 1, vector<int>(n + 1, 0));
        seg.resize(M + 1);
        for (int k = 0; k <= M; k++) {
            seg[k].init(n + 1, NEG);
        }
        nxt.assign(M + 1, vector<int>(n + 2));
        for (int k = 0; k <= M; k++) {
            for (int i = 0; i <= n + 1; i++) {
                nxt[k][i] = i;
            }
        }
        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
            vis[0][i] = 1;
            seg[0].update(i, prefix[i]);
            nxt[0][i] = i + 1;
        }
        ll answer = NEG;
        for (int k = 1; k <= M; k++) {
            if (1LL * k * L > n) break;
            answer = max(answer, dfs(0, k));
        }
        return answer;
    }
};