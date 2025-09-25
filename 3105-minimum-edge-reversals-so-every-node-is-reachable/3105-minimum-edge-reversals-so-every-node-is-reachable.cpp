class Solution {
public:
vector<vector<pair<int,int>>>adj;
vector<int>ans;
int dfs(int u,int par){
    int flips=0;
    for(auto &[v,cost]:adj[u]){
        if(v==par) continue;
        flips+=(cost+dfs(v,u));
    }
    return flips;
}
void rerootdfs(int u,int par){
for(auto &[v,cost]:adj[u]){
    if(v==par) continue;
    if(cost==0) ans[v]=ans[u]+1;
    else ans[v]=ans[u]-1;
    rerootdfs(v,u);
  }
}
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        adj.assign(n,{});
        ans.assign(n,0);
        for(auto &e:edges){
            adj[e[0]].push_back({e[1],0});
            adj[e[1]].push_back({e[0],1});
        }
        ans[0]=dfs(0,-1);
        rerootdfs(0,-1);
        return ans;
    }
};