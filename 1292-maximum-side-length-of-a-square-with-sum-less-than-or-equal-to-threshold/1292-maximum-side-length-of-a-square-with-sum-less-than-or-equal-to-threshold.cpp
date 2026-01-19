class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>p(m+1,vector<int>(n+1,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                p[i+1][j+1]=mat[i][j]+p[i][j+1]+p[i+1][j]-p[i][j];
            }
        }
        for(int len=min(m,n);len>=1;len--){
            for(int i=0;i<=m-len;i++){
                for(int j=0;j<=n-len;j++){
                    int sum=p[i+len][j+len]-p[i][j+len]-p[i+len][j]+p[i][j];
                    if(sum<=threshold) return len;
                }
            }
        }
        return 0;
    }
};