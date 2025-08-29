class Solution {
public:
    int n;
    vector<vector<int>> adj;
    int t[100001][15];
    int dfs(int u, int par, int halvedCount, vector<int>& coins, int k) {
        if(halvedCount>=14) return 0;
        if(t[u][halvedCount]!=-1) return t[u][halvedCount];
        int curVal = coins[u] >> halvedCount;
        int op1 = curVal - k;
        int op2 = curVal / 2;
        for (auto &v : adj[u]) {
            if (v == par) continue;
            op1 += dfs(v, u, halvedCount, coins, k);
            op2 += dfs(v, u, halvedCount + 1, coins, k);
        }
        return t[u][halvedCount]=max(op1, op2);
    }

    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        n = coins.size();
        adj.assign(n, {});
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        memset(t,-1,sizeof(t));
        return dfs(0, -1, 0, coins, k);
    }
};