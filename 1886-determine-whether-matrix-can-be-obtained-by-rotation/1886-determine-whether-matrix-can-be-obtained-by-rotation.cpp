class Solution {
public:
    vector<vector<int>> f(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> grid(m, vector<int>(n));
        int j=n-1;
        for(auto &row:mat){
            for(int i=0;i<m;i++){
               grid[i][j]=row[i];
            }
            j--;
        }
        mat=grid;
        return grid;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int m = mat.size();
        int n = mat[0].size();
        if (mat == target)
            return true;
        for (int i = 0; i < 4; i++) {
            auto grid = f(mat);
            if(grid==target) return true;
        }
        return false;
    }
};