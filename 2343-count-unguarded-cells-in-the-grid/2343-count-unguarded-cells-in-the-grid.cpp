class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int cnt=0;
        vector<vector<int>>grid(m,vector<int>(n,0));
        for(auto g:guards) grid[g[0]][g[1]]=3;
        for(auto w:walls)  grid[w[0]][w[1]]=2;
        for(auto g:guards){
            int i=g[0],j=g[1];
            for(int k=j-1;k>=0;k--){
                if(grid[i][k]==3 || grid[i][k]==2) break;
                grid[i][k]=1;
            }
            for(int k=j+1;k<n;k++){
                if(grid[i][k]==3 || grid[i][k]==2) break;
                grid[i][k]=1;
            }
            for(int k=i-1;k>=0;k--){
                if(grid[k][j]==3 || grid[k][j]==2) break;
                grid[k][j]=1;
            }
            for(int k=i+1;k<m;k++){
                if(grid[k][j]==3 || grid[k][j]==2) break;
                grid[k][j]=1;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) cnt++;
            }
        }
        return cnt;
    }
};