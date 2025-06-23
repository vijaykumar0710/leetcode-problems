class Solution {
public:
    vector<vector<int>> adj;
    int result = 0;

    long long dfs(int node, int parent, vector<int>& cost) {
        long long maxSub = 0;
        vector<long long> childSums;

        for (int child : adj[node]) {
            if (child == parent) continue;
            long long sub = dfs(child, node, cost);
            maxSub = max(maxSub, sub);
            childSums.push_back(sub);
        }

        // Increase nodes in child paths to match maxSub
        for (auto& sub : childSums) {
            if (sub < maxSub) result++;
        }

        return cost[node] + maxSub;
    }

    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0, -1, cost);
        return result;
    }
};
