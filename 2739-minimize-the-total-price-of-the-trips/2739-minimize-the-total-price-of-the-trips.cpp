class Solution {
public:
vector<vector<int>>adj;
vector<int>freq;
bool dfs_fre(int start,int end,int par){
if(start==end){
    freq[start]++;
    return true;
}
for(auto &v:adj[start]){
    if(v==par) continue;
    if(dfs_fre(v,end,start)){
        freq[start]++;
        return true;
      }
   }
   return false;
}

pair<int,int> dfs_res(int u,int par,vector<int>&price){
   int cost=price[u]*freq[u];
   int half_cost=(price[u]/2)*freq[u];
  for(auto &v:adj[u]){
    if(v==par) continue;
    auto child_cost=dfs_res(v,u,price);
    cost+=min(child_cost.first,child_cost.second);
    half_cost+=child_cost.first;
  }
  return {cost,half_cost};
}
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        adj.assign(n,{});
        freq.assign(n,0);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(auto &t:trips) dfs_fre(t[0],t[1],-1);
        auto res=dfs_res(0,-1,price);
        return min(res.first,res.second);
    }
};