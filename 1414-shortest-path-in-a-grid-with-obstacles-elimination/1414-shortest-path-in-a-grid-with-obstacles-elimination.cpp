class Solution {
public:
vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
int m,n;
int bfs(int row,int col,vector<vector<int>>& grid,int k){
vector<vector<vector<bool>>>vis(m,vector<vector<bool>>(n,vector<bool>(k+1,false)));
queue<vector<int>>q;
vis[row][col][0]=true;
q.push({row,col,0,0});
while(!q.empty()){
   auto vec=q.front();q.pop();
   int r=vec[0],c=vec[1],steps=vec[2],obs=vec[3];
   if(r==m-1 && c==n-1) return steps; 
   for(auto &dir:directions){
     int n_r=r+dir[0],n_c=c+dir[1];
     if(n_r<0 || n_c<0 || n_r>=m || n_c>=n) continue;
     int new_obs=obs;
     if(grid[n_r][n_c]==1) new_obs++;
     if(new_obs>k) continue;
     if(vis[n_r][n_c][new_obs]) continue; 
     vis[n_r][n_c][new_obs]=true;
     q.push({n_r,n_c,steps+1,new_obs});
    }
  }
  return -1;
}
    int shortestPath(vector<vector<int>>& grid, int k) {
        m=grid.size(),n=grid[0].size();
        return bfs(0,0,grid,k);
    }
};