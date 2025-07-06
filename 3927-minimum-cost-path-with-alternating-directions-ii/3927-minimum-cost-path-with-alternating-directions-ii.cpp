class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
       vector<vector<long long>>t(m,vector<long long>(n));
       t[0][0]=1;
       for(int j=1;j<n;j++) t[0][j]=t[0][j-1]+waitCost[0][j]+(1)*(j+1);
       for(int i=1;i<m;i++) t[i][0]=t[i-1][0]+waitCost[i][0]+(i+1)*(1);
       for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            t[i][j]=min(t[i][j-1],t[i-1][j])+waitCost[i][j]+(i+1)*(j+1);
         }
       }
       return t[m-1][n-1]-waitCost[m-1][n-1];
    }
};