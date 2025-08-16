class Solution {
public:
    vector<pair<int,int>> src;  // cells with >1 stones
    vector<pair<int,int>> trg;  // cells with 0 stones
    int m, n;
    int dfs(int idx, int mask){
        if(idx == src.size()) return 0;

        int ans = INT_MAX;
        for(int t = 0; t < trg.size(); t++){
            if(!(mask & (1<<t))){
                // manhattan distance from src[idx] to trg[t]
                int d = abs(src[idx].first  - trg[t].first)
                        + abs(src[idx].second - trg[t].second);
                ans = min(ans, d + dfs(idx+1, mask | (1<<t)));
            }
        }
        return ans;
    }

    int minimumMoves(vector<vector<int>>& g) {
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(g[i][j] == 0) trg.push_back({i,j});
                while(g[i][j] > 1){
                    src.push_back({i,j});
                    g[i][j]--;
                }
            }
        }
        // backtracking / bitmask matching
        return dfs(0, 0);
    }
};