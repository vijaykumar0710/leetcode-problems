class Solution {
public:
vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{1,1},{-1,1},{1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]==1 || grid[m-1][n-1]==1) return -1;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        queue<vector<int>>q;
        q.push({0,0,1});
        vis[0][0]=true;
        while(!q.empty()){
            auto vec=q.front();
            q.pop();
            int r=vec[0],c=vec[1],dis=vec[2];
            if(r==m-1 && c==n-1) return dis;
            for(auto &dir:directions){
                int n_r=r+dir[0],n_c=c+dir[1];
                if(n_r<0||n_r>=m||n_c<0||n_c>=n||grid[n_r][n_c]==1||vis[n_r][n_c]) continue;
                vis[n_r][n_c]=true;
                q.push({n_r,n_c,dis+1});
            }
        }
        return -1;
    }
};