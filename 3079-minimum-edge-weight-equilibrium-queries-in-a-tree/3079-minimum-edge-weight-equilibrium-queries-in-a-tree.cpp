class Solution {
public:
    static const int LOG = 17;
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
           int u = e[0], v = e[1], w = e[2] - 1;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> depth(n);
        vector<vector<int>> up(LOG, vector<int>(n));
        vector<vector<vector<int>>> cost(LOG, vector<vector<int>>(n, vector<int>(26, 0)));

        function<void(int,int,int)> dfs = [&](int u, int p, int d) {
            up[0][u] = p;
            depth[u] = d;
            for (auto &nx : adj[u]) {
                int v = nx.first, w = nx.second;
                if (v == p) continue;
                cost[0][v][w]++;
                dfs(v, u, d + 1);
            }
        };
        dfs(0, 0, 0);

        for (int i = 1; i < LOG; i++) {
            for (int v = 0; v < n; v++) {
                int par = up[i-1][v];
                up[i][v] = up[i-1][par];
                for (int b = 0; b < 26; b++) {
                    cost[i][v][b] = cost[i-1][v][b] + cost[i-1][par][b];
                }
            }
        }

        auto lift = [&](int &u, int k, vector<int> &cnt) {
            for (int i = 0; i < LOG; i++) {
                if (k & (1 << i)) {
                    for (int b = 0; b < 26; b++) {
                        cnt[b] += cost[i][u][b];
                    }
                    u = up[i][u];
                }
            }
        };

        auto lca = [&](int u, int v, vector<int> &cntU, vector<int> &cntV) {
            if (depth[u] < depth[v]) swap(u, v);
            lift(u, depth[u] - depth[v], cntU);
            if (u == v) return u;
            for (int i = LOG - 1; i >= 0; i--) {
                if (up[i][u] != up[i][v]) {
                    for (int b = 0; b < 26; b++) {
                        cntU[b] += cost[i][u][b];
                        cntV[b] += cost[i][v][b];
                    }
                    u = up[i][u];
                    v = up[i][v];
                }
            }
            for (int b = 0; b < 26; b++) {
                cntU[b] += cost[0][u][b];
                cntV[b] += cost[0][v][b];
            }
            return up[0][u];
        };

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto &q : queries) {
            vector<int> cntU(26, 0), cntV(26, 0);
            lca(q[0], q[1], cntU, cntV);
            vector<int> tot(26);
            for (int i = 0; i < 26; i++) tot[i] = cntU[i] + cntV[i];
            int sum = 0, mx = 0;
            for (int i = 0; i < 26; i++) {
                sum += tot[i];
                mx = max(mx, tot[i]);
            }
            ans.push_back(sum - mx);
        }
        return ans;
    }
};