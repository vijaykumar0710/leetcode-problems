class Solution {
public:
int m,n;
vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
bool bfs(int row,int col,vector<vector<int>>& grid, int health){
    vector<vector<int>>visited_min(m,vector<int>(n,-1));
    queue<vector<int>>q;
    if(grid[0][0]==1) health--;
    q.push({0,0,health});
    visited_min[0][0]=health;
    while(!q.empty()){
        int sz=q.size();
        while(sz--){ 
            auto vec=q.front();
            int r=vec[0],c=vec[1],h=vec[2];
             q.pop();
            if(h>=1 && r==m-1 && c==n-1) return true;
            for(auto &dir:directions){
               int n_r=r+dir[0];
               int n_c=c+dir[1];
               if(n_r>=0 && n_r<m && n_c>=0 && n_c<n){
                int new_h=h-grid[n_r][n_c];
                if(new_h>=1 && new_h>visited_min[n_r][n_c]){ 
                visited_min[n_r][n_c]=new_h;
                q.push({n_r,n_c,new_h});
                }
               }
            }
          }
        }
    return false;
}
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m=grid.size();
        n=grid[0].size();
        return bfs(0,0,grid,health);
    }
};