class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>t(n,vector<int>(n,0));
        for(int j=0;j<n;j++) t[0][j]=matrix[0][j];
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int x1=INT_MAX,x2=INT_MAX,x3=INT_MAX;
                if(i-1>=0 && j-1>=0) x1=t[i-1][j-1];
                if(i-1>=0) x2=t[i-1][j];
                if(i-1>=0 && j+1<n) x3=t[i-1][j+1];
                t[i][j]+=matrix[i][j]+min({x1,x2,x3});
            }
        }
        int mini=INT_MAX;
       for(int j=0;j<n;j++){
        mini=min(mini,t[n-1][j]);
       }
       return mini;
    }
};