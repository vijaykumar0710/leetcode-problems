class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>>t(m,vector<int>(m,1e5));
        t[0][0]=triangle[0][0];
        int res=INT_MAX;
        for(int i=1;i<m;i++){
            for(int j=0;j<i;j++){
                int val1=INT_MAX,val2=INT_MAX;
                if(i-1>=0) val1=t[i-1][j];
                if(i-1>=0 && j-1>=0) val2=t[i-1][j-1];
                t[i][j]=triangle[i][j]+min(val1,val2);
            }
        }
        for(int j=0;j<m;j++) res=min(res,t[m-1][j]);
        return res;
    }
};