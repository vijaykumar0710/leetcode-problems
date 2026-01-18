class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>p;
        p.resize(m+1,vector<int>(n+1,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              p[i+1][j+1]=mat[i][j]+p[i][j+1]+p[i+1][j]-p[i][j];
            }
        }
        vector<vector<int>>ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int r1=max(0,i-k),c1=max(0,j-k);
                int r2=min(m-1,i+k),c2=min(n-1,j+k);
                ans[i][j]=p[r2+1][c2+1]-p[r1][c2+1]-p[r2+1][c1]+p[r1][c1];
            }
        }
        return ans;
    }
};