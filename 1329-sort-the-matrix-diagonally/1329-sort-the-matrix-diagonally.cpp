class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        map<int,multiset<int>>mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[j-i].insert(mat[i][j]);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
            mat[i][j]=*mp[j-i].begin();
            mp[j-i].erase(mp[j-i].begin());
            }
        }
        return mat;
    }
};