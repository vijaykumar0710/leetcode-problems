class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>p(m+1,vector<int>(n+1,0));
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              p[i+1][j+1]=grid[i][j]+p[i][j+1]+p[i+1][j]-p[i][j];
              if(p[i+1][j+1]<=k) res++;
            }
        }
        return res;
    }
};