class Solution {
public:
    int countSquares(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>>t(m,vector<int>(n,0));
    int res=0;
    for(int i=0;i<m;i++) if(grid[i][0]==1) t[i][0]=1,res++;
    for(int j=1;j<n;j++) if(grid[0][j]==1) t[0][j]=1,res++;
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(grid[i][j]==1){
                t[i][j]=1+min({t[i-1][j],t[i][j-1],t[i-1][j-1]});
                res+=t[i][j];
            }
        }
      }
      return res;
    }
};