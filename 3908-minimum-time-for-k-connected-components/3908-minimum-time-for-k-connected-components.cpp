class Solution {
public:
    vector<int> parent, rank;

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void Union(int x, int y) {
        int x_par = find(x);
        int y_par = find(y);
        if (x_par == y_par) return;
        if (rank[x_par] > rank[y_par]) {
            parent[y_par] = x_par;
        } else if (rank[x_par] < rank[y_par]) {
            parent[x_par] = y_par;
        } else {
            parent[y_par] = x_par;
            rank[x_par]++;
        }
    }

    bool isValid(int n, vector<vector<int>>& edges, int mid, int k) {
        // Reset DSU
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        // Keep only edges with time > mid (i.e., not removed yet)
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], t = edge[2];
            if (t > mid) {
                Union(u, v);
            }
        }

        // Count number of connected components
        unordered_set<int> comp;
        for (int i = 0; i < n; i++) {
            comp.insert(find(i));
        }

        return comp.size() >= k;
    }

    int minTime(int n, vector<vector<int>>& edges, int k) {

        parent.resize(n);
        rank.resize(n);

        int lo = 0, hi = 1e9, ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (isValid(n, edges, mid, k)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
