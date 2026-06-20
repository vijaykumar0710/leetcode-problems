class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& rest) {
        rest.push_back({1, 0});
        sort(rest.begin(), rest.end());
        int m = rest.size();
        if(rest[m-1][0]!=n){
            rest.push_back({n, n - 1});
            m++;
        }
            for (int i = 1; i < m; i++) {
            int dist = rest[i][0] - rest[i-1][0];
            rest[i][1] = min(rest[i][1], rest[i-1][1] + dist);
        }
            for (int i = m - 2; i >= 0; i--) {
            int dist = rest[i+1][0] - rest[i][0];
            rest[i][1] = min(rest[i][1], rest[i+1][1] + dist);
        }
        int max_height = 0;
        for (int i = 1; i < m; i++) {
            int l_id = rest[i-1][0];
            int l_height = rest[i-1][1];
            int r_id = rest[i][0];
            int r_height = rest[i][1];
            int current_peak = (l_height + r_height + (r_id - l_id)) / 2;
            max_height = max(max_height, current_peak);
        }
        
        return max_height;
    }
};