class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        for(int j=0;j<n;j++){
            for(int i=1;i<m;i++){
               if(mat[i][j]==1) mat[i][j]=1+mat[i-1][j];
            }
        }
        int area=0;
        for(auto &row:mat){
            sort(row.rbegin(),row.rend());
            for(int j=0;j<n;j++){
                area=max(area,(j+1)*row[j]);
            }
        }
        return area;
    }
};