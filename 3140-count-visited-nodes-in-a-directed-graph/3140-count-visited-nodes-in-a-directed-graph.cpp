class Solution {
public:
    vector<int> res;
    vector<int> state; // 0 = unvisited, 1 = inRecursion, 2 = done

    int dfs(int u, vector<int>& edges) {
        if (state[u] == 2) return res[u];      // already computed
        if (state[u] == 1) {                   // cycle detected starting at u
            int v = edges[u];
            int len = 1;
            while (v != u) { v = edges[v]; ++len; }  // count cycle length

            // mark whole cycle with its length
            v = u;
            do {
                res[v] = len;
                state[v] = 2;
                v = edges[v];
            } while (v != u);
            return res[u]; // = len
        }

        state[u] = 1;                 // enter recursion stack
        int v = edges[u];
        int ans = 1 + dfs(v, edges);  // take child's answer

        // if u was not finalized during cycle marking, finalize now
        if (state[u] != 2) {
            res[u] = ans;
            state[u] = 2;
        }
        return res[u];
    }

    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        res.assign(n, 0);
        state.assign(n, 0);

        for (int i = 0; i < n; ++i)
            if (state[i] == 0) dfs(i, edges);
        return res;
    }
};