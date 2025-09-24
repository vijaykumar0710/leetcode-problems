class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>>t(m,vector<int>(n,0));
        vector<int>res;
        t[0][0]=matrix[0][0];
        res.push_back(t[0][0]);
        for(int j=1;j<n;j++) t[0][j]=matrix[0][j]^t[0][j-1],res.push_back(t[0][j]);
        for(int i=1;i<m;i++) t[i][0]=matrix[i][0]^t[i-1][0],res.push_back(t[i][0]);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                t[i][j]=matrix[i][j]^t[i-1][j]^t[i][j-1]^t[i-1][j-1];
                res.push_back(t[i][j]);
            }
        }
       sort(res.rbegin()+(k-1),res.rend());
       return res[k-1];
    }
};