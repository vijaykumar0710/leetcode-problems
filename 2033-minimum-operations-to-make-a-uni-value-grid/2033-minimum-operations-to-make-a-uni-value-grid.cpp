class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size();
        int n=grid[0].size();
        int sm=grid[0][0]%x;
        vector<int>vec(m*n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vec[i*n+j]=grid[i][j];
                if(grid[i][j]%x!=sm) return -1;
            }
        }
        int op=0;
        sort(vec.begin(),vec.end());
        int tar=vec[vec.size()/2];
        for(int i=0;i<vec.size();i++){
           op+=abs((vec[i]-tar)/x);
        }
        return op;
    }
};