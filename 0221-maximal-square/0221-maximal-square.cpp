class Solution {
public:
    int maximalSquare(vector<vector<char>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    int max_size=0;
    vector<vector<int>>t(m,vector<int>(n,0));
    for(int i=0;i<m;i++) if(grid[i][0]=='1') t[i][0]=1, max_size=max(max_size,t[i][0]);
    for(int j=0;j<n;j++) if(grid[0][j]=='1') t[0][j]=1, max_size=max(max_size,t[0][j]);
    for(int i=1;i<m;i++){
     for(int j=1;j<n;j++){
       if(grid[i][j]=='1'){ 
          t[i][j]=1+min({t[i-1][j],t[i][j-1],t[i-1][j-1]});
          max_size=max(max_size,t[i][j]);
          }
        }
      }
      return max_size*max_size;
    }
};