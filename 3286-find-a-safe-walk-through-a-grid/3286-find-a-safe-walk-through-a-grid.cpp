class Solution {
public:
vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
int m,n;
bool bfs(int r,int c,vector<vector<int>>& grid, int health){
  vector<vector<bool>>vis(m,vector<bool>(n,false));
  deque<vector<int>>dq;
  vis[r][c]=true;
  if(grid[r][c]==1) health--;
  dq.push_back({r,c,health});
  while(!dq.empty()){ 
  auto vec=dq.front();dq.pop_front();
  int row=vec[0],col=vec[1],h=vec[2];
  if(row==m-1 && col==n-1 && h>=1) return true;
  for(auto &dir:directions){
    int n_r=row+dir[0],n_c=col+dir[1];
    if(n_r<0 || n_c<0 || n_r>=m || n_c>=n || vis[n_r][n_c]) continue;
    vis[n_r][n_c]=true;
    if(grid[n_r][n_c]==0) dq.push_front({n_r,n_c,h});
    else dq.push_back({n_r,n_c,h-1});
    }
  }
  return false;
}
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m=grid.size(),n=grid[0].size();
        return bfs(0,0,grid,health);
    }
};