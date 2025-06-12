class Solution {
public:
long long solve(int i,int freetime,vector<int>&cost,vector<int>&time,vector<vector<long long>>&t,int n){
   if(i==n){
       return freetime>=0?0:INT_MAX;
   }
    if(t[i][freetime+n]!=-1) return t[i][freetime+n];
    int max_free_time=min(n,freetime+time[i]);
    long long paid_painter=cost[i]+solve(i+1,max_free_time,cost,time,t,n);
    long long free_painter=solve(i+1,freetime-1,cost,time,t,n);

    return t[i][freetime+n]=min(paid_painter,free_painter);
}
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        vector<vector<long long>>t(n+1,vector<long long>(2*n+1,-1));
        return solve(0,0,cost,time,t,n);
    }
};