class Solution {
public:
int m,n;
vector<vector<int>>directions={{1,0},{0,-1},{-1,0},{0,1}};
void f(vector<vector<char>>& grid,int i,int j){
    queue<pair<int,int>>q;
    q.push({i,j});
    grid[i][j]='0';
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        for(auto dir:directions){
            int n_r=row+dir[0];
            int n_c=col+dir[1];
            if(n_r<0 || n_r>=m || n_c<0 || n_c>=n || grid[n_r][n_c]!='1') continue;
            grid[n_r][n_c]='0';
            q.push({n_r,n_c});
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
         m=grid.size();
         n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              if(grid[i][j]=='1'){
                cnt++;
                f(grid,i,j);
              }  
            }
        }
        return cnt;
    }
};