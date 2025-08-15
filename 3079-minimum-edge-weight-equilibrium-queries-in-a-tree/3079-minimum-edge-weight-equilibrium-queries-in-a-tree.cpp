class Solution {
public:
    static const int MAXN = 10005;
    static const int LOG = 15;

    vector<pair<int,int>> adj[MAXN]; // adjacency list: {neighbor, weight}
    int up[LOG][MAXN];               // Binary lifting table
    int depth[MAXN];                 // depth from root
    int cnt[MAXN][27];               // prefix count of each weight (weights 1..26)

    void dfs(int u, int parent) {
        up[0][u] = parent;
        for(auto &[v, w] : adj[u]) {
            if(v == parent) continue;
            depth[v] = depth[u] + 1;
            for(int i = 1; i <= 26; i++) cnt[v][i] = cnt[u][i];
            cnt[v][w]++;
            dfs(v, u);
        }
    }

    void build_lca(int n) {
        for(int k = 1; k < LOG; k++) {
            for(int v = 0; v < n; v++) {
                if(up[k-1][v] != -1)
                    up[k][v] = up[k-1][up[k-1][v]];
                else
                    up[k][v] = -1;
            }
        }
    }

    int get_lca(int u, int v) {
        if(depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];
        for(int k = LOG-1; k >= 0; k--) {
            if((diff >> k) & 1) u = up[k][u];
        }

        if(u == v) return u;

        for(int k = LOG-1; k >= 0; k--) {
            if(up[k][u] != -1 && up[k][u] != up[k][v]) {
                u = up[k][u];
                v = up[k][v];
            }
        }

        return up[0][u];
    }

    int minOperations(int u, int v) {
        int lca = get_lca(u, v);
        int path_len = depth[u] + depth[v] - 2 * depth[lca];

        int max_freq = 0;
        for(int w = 1; w <= 26; w++) {
            int freq = cnt[u][w] + cnt[v][w] - 2 * cnt[lca][w];
            max_freq = max(max_freq, freq);
        }

        return path_len - max_freq;
    }

    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        for(int i = 0; i < n; i++) adj[i].clear();
        memset(cnt, 0, sizeof(cnt));
        memset(up, -1, sizeof(up));
        memset(depth, 0, sizeof(depth));

        for(auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        depth[0] = 0;
        dfs(0, -1);
        build_lca(n);

        vector<int> ans;
        for(auto &q : queries) {
            ans.push_back(minOperations(q[0], q[1]));
        }

        return ans;
    }
};