class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>grid(n,vector<int>(n,0));
        for(auto &q:queries){
            int r1=q[0],c1=q[1];
            int r2=q[2],c2=q[3];
            for(int i=min(r1,r2);i<=max(r1,r2);i++){
                for(int j=min(c1,c2);j<=max(c1,c2);j++){
                    grid[i][j]+=1;
                }
            }
        }
        return grid;
    }
};