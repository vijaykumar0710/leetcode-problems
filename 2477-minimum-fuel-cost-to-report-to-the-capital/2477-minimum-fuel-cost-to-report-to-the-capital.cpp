class Solution {
public:
    long long total_cost = 0;
    int k;
    unordered_map<int, vector<int>> adj;
    int dfs(int u, int par) {
        long long people = 1;
        for (auto& v : adj[u]) {
            if (v == par)
                continue;
            people += dfs(v, u);
        }
        if (u != 0) {
            total_cost += (people + k - 1) / k;
        }
        return people;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        k = seats;
        for (auto& e : roads) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0, -1);
        return total_cost;
    }
};