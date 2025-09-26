class Solution {
public:
int n;
vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
vector<vector<int>>dist;
void bfs_dist(vector<vector<int>>& grid){
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1) { 
                dist[i][j]=0;
                q.push({i,j});
            }
        }
    }
  while(!q.empty()){
    auto vec=q.front();q.pop();
    int r=vec.first,c=vec.second;
    for(auto &dir:directions){
        int n_r=r+dir[0],n_c=c+dir[1];
        if(n_r<0 || n_c<0 || n_r>=n || n_c>=n ||  dist[n_r][n_c]<=dist[r][c]+1) continue;
        dist[n_r][n_c]=dist[r][c]+1;
        q.push({n_r,n_c});
    }
  }
}
bool isValid_bfs(vector<vector<int>>& grid,int mid){
   vector<vector<bool>>vis(n,vector<bool>(n,false));
   queue<pair<int,int>>q;
   q.push({0,0});
   vis[0][0]=true;
   while(!q.empty()){
    auto vec=q.front();q.pop();
    int r=vec.first,c=vec.second;
    if(dist[r][c]<mid) return false;
    if(r==n-1 && c==n-1) return true;
    for(auto &dir:directions){
        int n_r=r+dir[0],n_c=c+dir[1];
        if(n_r<0 || n_c<0 || n_r>=n || n_c>=n || vis[n_r][n_c]|| dist[n_r][n_c]<mid) continue;
        vis[n_r][n_c]=true;
        q.push({n_r,n_c});
     }
   }
   return false;
}
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n=grid.size();
        dist.assign(n,vector<int>(n,1e9));
        bfs_dist(grid);
        int l=0,r=800;
        int res=INT_MIN;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid_bfs(grid,mid)){
                res=mid;
                l=mid+1;
            }else r=mid-1;
        }
        return res;
    }
};