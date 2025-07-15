class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int N = 1 << n;
        int target = N - 1;
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            vector<vector<int>> visited(N, vector<int>(n, false));
            queue<pair<int, int>> qu;
            qu.push({1 << i, i});
            visited[1 << i][i] = true;
            int steps = 0;
            while (!qu.empty()) {
                int sz=qu.size();
                while(sz--){ 
                int mask = qu.front().first;
                int u = qu.front().second;
                qu.pop();
                if (mask == target) {
                    res = min(res, steps);
                    break;
                }
                for (auto& v : graph[u]) {
                    if (!visited[mask | (1 << v)][v]) {
                        visited[mask | (1 << v)][v] = true;
                        qu.push({mask|(1 << v), v});
                    }
                }
            }
            steps++;
            }
        }
        return res;
    }
};