class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> degree(n, 0);
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        queue<int> q;
        vector<bool> deleted(n, false);
        for (int i = 1; i < n; i++) {
            if (!hasApple[i] && degree[i] == 1 && !deleted[i]) {
                deleted[i] = true;
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();q.pop();
            deleted[u] = true;
            for (auto& v : adj[u]) {
                    degree[v]--;
                    if (v!=0 && degree[v] == 1 && !hasApple[v] && !deleted[v]) {
                        q.push(v);
                    }
            }
        }
        int res = 0;
        for (auto& e : edges) {
            if (!deleted[e[0]] && !deleted[e[1]])
                res+=2;
        }
        return res;
    }
};