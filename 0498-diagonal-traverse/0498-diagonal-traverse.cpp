class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int row = mat.size(), col = mat[0].size();
    vector<int> ans;
    for (int d = 0; d < row + col - 1; d++) {
        vector<int> temp;
        for (int i = 0; i <= d; i++) {
            int j = d - i;
            if (i < row && j < col) {
                temp.push_back(mat[i][j]);
            }
        }
        if (d % 2 == 0) reverse(temp.begin(), temp.end());
        ans.insert(ans.end(), temp.begin(), temp.end());
    }
    return ans;
}
};