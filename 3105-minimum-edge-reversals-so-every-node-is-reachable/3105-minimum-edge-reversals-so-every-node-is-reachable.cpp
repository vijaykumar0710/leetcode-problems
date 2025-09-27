class Solution {
public:
vector<vector<pair<int,int>>>adj;
vector<int>ans;
void dfs(int u,int par){
for(auto [v,cost]:adj[u]){
    if(par==v) continue;
    ans[0]+=cost;
    dfs(v,u);
   }
}
void reroot_dfs(int u,int par){
  for(auto [v,cost]:adj[u]){
    if(v==par) continue;
    if(cost==0) ans[v]=ans[u]+1;
    else ans[v]=ans[u]-1;
    reroot_dfs(v,u);
  }
}
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        adj.assign(n,{});
        ans.assign(n,0);
        for(auto &e:edges){
           adj[e[0]].push_back({e[1],0});
           adj[e[1]].push_back({e[0],1});
        }
        dfs(0,-1);
        reroot_dfs(0,-1);
        return ans;
    }
};