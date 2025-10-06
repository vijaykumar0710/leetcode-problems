class Solution {
public:
vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
int m,n;
bool bfs(vector<vector<int>>& grid,int mid){
  vector<vector<bool>>vis(m,vector<bool>(n,false));
  queue<pair<int,int>>q;
  if(grid[0][0]<=mid){ q.push({0,0}); vis[0][0]=true; }
  while(!q.empty()){
    int r=q.front().first,c=q.front().second; q.pop();
    if(r==m-1 && c==n-1) return true;
    for(auto &dir:directions){
        int n_r=r+dir[0],n_c=c+dir[1];
        if(n_r<0 || n_c<0 || n_r>=m || n_c>=n || vis[n_r][n_c] || grid[n_r][n_c]>mid) continue;
        vis[n_r][n_c]=true;
        q.push({n_r,n_c});
    }
  }
  return false;
}
    int swimInWater(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        int l=0,r=2500, res=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(bfs(grid,mid)){ res=mid; r=mid-1;}
             else l=mid+1;
        }
        return res;
    }
};