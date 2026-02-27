class Solution {
public:
unordered_map<int,vector<int>>adj;
vector<int>in1,in2,c1,out;
void dfs1(int u,int par){
    for(auto &v:adj[u]){
        if(v==par) continue;
        dfs1(v,u);
        int dist=in1[v]+1;
        if(dist>in1[u]){
        in2[u]=in1[u];
        in1[u]=dist;
        c1[u]=v;
        }else if(dist>in2[u]){
         in2[u]=dist;
        }
    }
}

void dfs2(int u,int par){
  for(auto &v:adj[u]){
    if(v==par) continue;
    if(v==c1[u]) out[v]=1+max(out[u],in2[u]);
    else out[v]=1+max(in1[u],out[u]);
    dfs2(v,u);
  }
}

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        adj.clear();
        in1.assign(n,0);
        in2.assign(n,0);
        c1.assign(n,-1);
        out.assign(n,0);
        for(auto &e:edges){
          adj[e[0]].push_back(e[1]);
          adj[e[1]].push_back(e[0]);
        }
       dfs1(0,-1); // fill in1,in2 and c1 array
       dfs2(0,-1); // fill out array
       int maxi=INT_MIN,mini=INT_MAX;
       for(int i=0;i<n;i++){
        maxi=max(in1[i],out[i]);
        mini=min(mini,maxi);
       }
       vector<int>res;
       for(int i=0;i<n;i++){
        if(mini==max(in1[i],out[i])) res.push_back(i);
       }
       return res;
    }
};