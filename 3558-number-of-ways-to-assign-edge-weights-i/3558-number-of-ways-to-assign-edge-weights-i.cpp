class Solution {
public:
const int M=1e9+7;
int dfs(int u,int par,unordered_map<int,vector<int>>&adj){
    int depth=0;
    for(auto &v:adj[u]){
        if(v!=par){
            int val=dfs(v,u,adj);
            depth=max(depth,val);
        }
    }
    return depth+1;
}
long long mod_pow(long long b,long long e){
    long long res=1;
    b%=M;
    while(e){
        if(e%2) res=(res*b)%M;
        b=(b*b)%M;
        e/=2;
    }
    return res;
}
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int max_depth=dfs(1,-1,adj)-1;
        long long res=mod_pow(2,max_depth-1);
        return res;
    }
};