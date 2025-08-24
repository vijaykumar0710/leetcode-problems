class Solution {
public:
vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
    int longestIncreasingPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> inDegree(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(auto &dir:directions){
                    int r=i+dir[0],c=j+dir[1];
                    if(r<0 || c<0 || r>=m || c>=n || grid[r][c]<=grid[i][j])continue;
                    inDegree[r][c]++;
                }
            }
        }
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(inDegree[i][j]==0)
                   q.push({i,j});
            }
        }

      int max_len=0;
        while(!q.empty()){
            int sz=q.size();
            max_len++;
            while(sz--){ 
            auto [i,j]=q.front();
            q.pop();
             for(auto &dir:directions){
               int r=i+dir[0],c=j+dir[1];
                if(r<0 || c<0 || r>=m || c>=n || grid[r][c]<=grid[i][j])continue;
                inDegree[r][c]--;
                if(inDegree[r][c]==0) q.push({r,c});
              }
            }
        }
        return max_len;
    }
};