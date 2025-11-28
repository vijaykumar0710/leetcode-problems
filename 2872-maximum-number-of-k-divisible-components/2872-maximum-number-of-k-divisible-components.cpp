class Solution {
public:
long long f(int u,int p,vector<vector<int>>&adj,vector<int>&values,int k,int &cnt){
    long long sum=values[u];
    for(auto &v:adj[u]){
        if(v==p) continue;
        long long child=f(v,u,adj,values,k,cnt);
        sum+=child;
    }
    if(sum%k==0){
       cnt++;
       return 0LL;
    }
    return sum;
}
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        //unordered_map<int,vector<int>>adj;
        vector<vector<int>>adj(n);
        for(auto &e:edges){
            int u=e[0],v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt=0;
        f(0,-1,adj,values,k,cnt);
        return cnt;
    }
};