class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int j=y;j<y+k;j++){
            vector<int>temp;
            for(int i=x;i<x+k;i++){
                 temp.push_back(grid[i][j]);
            }
            for(int i=x;i<x+k;i++){
                grid[i][j]=temp.back();
                temp.pop_back();
            }
        }
        return grid;
    }
};