class Solution {
public:
int n;
vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
queue<vector<int>>q;
void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<bool>>&vis){
if(row<0 || row>=n || col<0 || col>=n || vis[row][col] || grid[row][col]==0) return;
vis[row][col]=true;
grid[row][col]=2;
q.push({row,col,0});
for(auto &dir:directions){
int r=row+dir[0],c=col+dir[1];
    dfs(r,c,grid,vis);
   }
}
  int shortestBridge(vector<vector<int>>& grid) {
        n=grid.size();
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        bool flag=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid,vis);
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        while(!q.empty()){
            auto vec=q.front(); q.pop();
            int r=vec[0];
            int c=vec[1];
            int step=vec[2];
            if(grid[r][c]==1) return step-1;
            for(auto &dir:directions){
            int n_r=r+dir[0],n_c=c+dir[1];
               if(n_r<0 || n_c<0 || n_r>=n || n_c>=n || vis[n_r][n_c]) continue;
               vis[n_r][n_c]=true;
               int new_step=step+1;
               q.push({n_r,n_c,new_step});
             }
        }
        return -1;
    }
};