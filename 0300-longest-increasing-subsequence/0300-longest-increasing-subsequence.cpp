class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] < nums[j]) {
                    adj[i].push_back(j);
                    indegree[j]++;
                }
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) if (indegree[i] == 0) q.push(i);
        vector<int> dist(n, 1);
        int ans = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                dist[v] = max(dist[v], dist[u] + 1);
                ans = max(ans, dist[v]);
                indegree[v]--;
                if (indegree[v]==0) q.push(v);
            }
        }
        return ans;
    }
};