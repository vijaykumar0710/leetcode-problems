class Solution {
public:
typedef long long ll;
ll f(int i,int freetime,vector<int>& cost, vector<int>& time,int n,vector<vector<ll>>&t){
    if(i>=n){
        return freetime>=0?0:INT_MAX;
    }
    if(t[i][freetime+n]!=-1) return t[i][freetime+n];
    ll max_time_need=min(n,freetime+time[i]);
    ll paid=cost[i]+f(i+1,max_time_need,cost,time,n,t);
    ll free=f(i+1,freetime-1,cost,time,n,t);
    return t[i][freetime+n]=min(paid,free);
}
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        vector<vector<ll>>t(n+1,vector<ll>(2*n+1,-1));
        return f(0,0,cost,time,n,t);
    }
};