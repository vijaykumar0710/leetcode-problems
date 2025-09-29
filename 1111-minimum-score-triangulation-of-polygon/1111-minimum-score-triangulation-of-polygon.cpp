class Solution {
public:
int t[51][51];
int f(int i,int j,vector<int>&values){
if(j-i==1) return 0;
if(t[i][j]!=-1) return t[i][j];
    int res=INT_MAX;
    for(int k=i+1;k<j;k++){
        int temp=values[i]*values[j]*values[k]+f(i,k,values)+f(k,j,values);
        res=min(res,temp);
    }
    return t[i][j]=res;
}
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        memset(t,-1,sizeof(t));
        return f(0,n-1,values);
    }
};