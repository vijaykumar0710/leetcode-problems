class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        int xp = find(x);
        int yp = find(y);
        if (xp == yp) return;
        if (rank[xp] < rank[yp]) {
            parent[xp] = yp;
        } else if (rank[xp] > rank[yp]) {
            parent[yp] = xp;
        } else {
            parent[yp] = xp;
            rank[xp]++;
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        parent.resize(c + 1);
        rank.resize(c + 1, 0);
        for (int i = 1; i <= c; ++i) parent[i] = i;
        for (auto& conn : connections) {
            unite(conn[0], conn[1]);
        }
        // Build component-wise online station sets
        unordered_map<int, set<int>> online_in_component;
        for (int i = 1; i <= c; ++i) {
            int root = find(i);
            online_in_component[root].insert(i);
        }
        vector<int> res;
        for (auto& q : queries) {
            int type = q[0];
            int x = q[1];
            int root = find(x);
            if (type == 1) {
                // Maintenance check
                if (online_in_component[root].count(x)) {
                    res.push_back(x); // Online
                } else {
                    if (online_in_component[root].empty()) {
                        res.push_back(-1);
                    } else {
                        res.push_back(*online_in_component[root].begin());
                    }
                }
            } else {
                // Go offline
                online_in_component[root].erase(x);
            }
        }

        return res;
    }
};
