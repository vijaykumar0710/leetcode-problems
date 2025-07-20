class Solution {
public:
typedef long long ll;
void dfs(int u,vector<vector<int>>&adj,vector<bool>&visited){
    visited[u]=true;
    for(auto &v:adj[u]){
         if(!visited[v])
           dfs(v,adj,visited);
    }
}
bool isValid(int mid,int n,vector<vector<int>>&edges){
    vector<vector<int>>adj(n);
    for(auto &e:edges){
    int u=e[0];
    int v=e[1];
    int wt=e[2];
    if(wt<=mid){
        adj[v].push_back({u});
        }
    }
    vector<bool>visited(n,false);
    dfs(0,adj,visited);
    for(int i=0;i<n;i++){
        if(!visited[i]) return false;
    }
   return true;
}
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        ll l=0,r=1e6;
        int res=-1;
        while(l<=r){
         int mid=l+(r-l)/2;
         if(isValid(mid,n,edges)){
             res=mid;
             r=mid-1;
         }else l=mid+1;
        }
        return res;
    }
};