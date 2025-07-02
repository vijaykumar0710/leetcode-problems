class Solution {
public:
int m,n;
int t[201][201];
int solve(int i,int j,vector<vector<int>>& grid){
    if(i>=m || j>=n) return INT_MAX;

    if(t[i][j]!=-1) return t[i][j];

    int right=solve(i,j+1,grid);
    int down=solve(i+1,j,grid);

   if(i==m-1 && j==n-1){
        if(grid[i][j]>=0)
          return 1;
        else{
            return abs(grid[i][j])+1;
        }
    }

    int res=min(right,down)-grid[i][j]; 
    return t[i][j]=res>0?res:1;
}
    int calculateMinimumHP(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        memset(t,-1,sizeof(t));
        return solve(0,0,grid);
    }
};