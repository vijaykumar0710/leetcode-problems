const int M=1e9+7;
class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
       vector<vector<unordered_map<int,int>>> t(m, vector<unordered_map<int,int>>(n));
        t[0][0][grid[0][0]]++;
        for(int j=1;j<n;j++){
            for(auto [x,cnt]:t[0][j-1]){
                t[0][j][grid[0][j]^x]=(t[0][j][grid[0][j]^x]+cnt)%M;
            }
        }
        for(int i=1;i<m;i++){
            for(auto [x,cnt]:t[i-1][0]){
                t[i][0][grid[i][0]^x]=(t[i][0][grid[i][0]^x]+cnt)%M;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
               for(auto [x,cnt]:t[i][j-1]){
                t[i][j][grid[i][j]^x]=(t[i][j][grid[i][j]^x]+cnt)%M;
               }
               for(auto [x,cnt]:t[i-1][j]){
                t[i][j][grid[i][j]^x]=(t[i][j][grid[i][j]^x]+cnt)%M;
               }
            }
        }
        int res=0;
        for(auto [x,cnt]:t[m-1][n-1]) if(x==k) res=(res+cnt)%M;
        return res%M; 
    }
};