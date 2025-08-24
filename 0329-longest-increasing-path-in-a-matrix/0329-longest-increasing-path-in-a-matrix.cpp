class Solution {
public:
int m,n;
vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
vector<vector<int>>t;
int dfs(vector<vector<int>>& grid,int i,int j){
    if(t[i][j]!=-1) return t[i][j];
    int len=1;
    for(auto &dir:directions){
        int r=dir[0]+i;
        int c=dir[1]+j;
        if(r<0 || c<0 || r==m || c==n || grid[r][c]<=grid[i][j]) continue;
        len=max(len,1+dfs(grid,r,c));
    }
    return t[i][j]=len;
}
    int longestIncreasingPath(vector<vector<int>>& grid) {
         m=grid.size();
         n=grid[0].size();
        int len=0;
        t.assign(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              len=max(len,dfs(grid,i,j));
            }
        }
        return len;
    }
};