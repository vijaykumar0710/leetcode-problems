class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>t(m,vector<int>(n,0));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1){
                    if(grid[i][j]>=0) t[i][j]=1;
                    else t[i][j]=abs(grid[i][j])+1;
                }
                else{ 
                int right=j+1>=n?1e9:t[i][j+1];
                int down=i+1>=m?1e9:t[i+1][j];
                int res=min(right,down)-grid[i][j];
                t[i][j]=res>0?res:1;
                }
            }
        }
        return t[0][0];
    }
};