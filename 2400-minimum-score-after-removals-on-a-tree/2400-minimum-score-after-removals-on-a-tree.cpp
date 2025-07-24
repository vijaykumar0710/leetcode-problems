class Solution {
public:
    vector<int> subtree_xor;
    vector<int> in, out; // Time-in and Time-out for ancestor checking
    int timer = 0;
    void dfs(int u, int par, vector<vector<int>>& adj, vector<int>& nums) {
        in[u] = ++timer;
        subtree_xor[u] = nums[u];
        for (int v : adj[u]) {
            if (v != par) {
                dfs(v, u, adj, nums);
                subtree_xor[u] ^= subtree_xor[v];
            }
        }
        out[u] = ++timer;
    }

    bool isAncestor(int u, int v) {
        // Returns true if u is ancestor of v
        return in[u] <= in[v] && out[v] <= out[u];
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);  // It’s undirected
        }

        subtree_xor.assign(n, 0);
        in.assign(n, 0);
        out.assign(n, 0);
        dfs(0, -1, adj, nums);
       int total_xor = subtree_xor[0];

        int res = INT_MAX;

        // Try all pairs of nodes to simulate removing 2 edges (on their subtree roots)
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a, b, c;

                if (isAncestor(i, j)) {
                    // j is in i's subtree
                    a = subtree_xor[j];
                    b = subtree_xor[i] ^ subtree_xor[j];
                    c = total_xor ^ subtree_xor[i];
                } else if (isAncestor(j, i)) {
                    // i is in j's subtree
                    a = subtree_xor[i];
                    b = subtree_xor[j] ^ subtree_xor[i];
                    c = total_xor ^ subtree_xor[j];
                } else {
                    // i and j are in different subtrees
                    a = subtree_xor[i];
                    b = subtree_xor[j];
                    c = total_xor ^ a ^ b;
                }

                int maxi = max({a, b, c});
                int mini = min({a, b, c});
                res = min(res, maxi - mini);
            }
        }
        return res;
    }
};
