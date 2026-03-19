class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<vector<int>> compo;
        vector<int> color(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                vector<int> comp;
                queue<int> q;
                q.push(i);
                color[i] = 0;
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    comp.push_back(u);
                    for (auto& v : adj[u]) {
                        if (color[v] == color[u])
                            return -1;
                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            q.push(v);
                        }
                    }
                }
                compo.push_back(comp);
            }
        }
        int res = 0;
        for (auto comp : compo) {
            int maxi = 0;
            for (auto i : comp) {
                queue<int> q;
                vector<int> dist(n + 1, 0);
                q.push(i);
                dist[i] = 1;
                int d = 1;
                while (!q.empty()) {
                    int u = q.front();
                    d = max(d, dist[u]);
                    q.pop();
                    for (auto& v : adj[u]) {
                        if (dist[v] == 0) {
                            dist[v] = dist[u] + 1;
                            q.push(v);
                        }
                    }
                }
                maxi = max(maxi, d);
            }
            res += maxi;
        }
        return res;
    }
};