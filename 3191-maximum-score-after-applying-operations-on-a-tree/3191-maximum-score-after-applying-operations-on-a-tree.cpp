class Solution {
public:
    long long total = 0;
    vector<vector<int>> adj;
    vector<int> vals;
    long long dfs(int u, int p) {
        long long sumChildren = 0;
        bool isLeaf = true;
        for (int v : adj[u]) {
            if (v == p) continue;
            isLeaf = false;
            sumChildren += dfs(v, u);
        }
        if (isLeaf) {
            return vals[u];
        }
        return min<long long>(vals[u], sumChildren);
    }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vals = values;
        adj.assign(n, {});
        total = 0;
        for (int i = 0; i < n; ++i) total += values[i];
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        long long remaining = dfs(0, -1);  
        return total - remaining;
    }
};