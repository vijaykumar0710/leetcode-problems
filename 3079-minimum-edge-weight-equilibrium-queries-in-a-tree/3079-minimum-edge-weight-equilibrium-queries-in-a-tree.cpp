class Solution {
public:
int N;
int LOG;
 unordered_map<int, vector<pair<int,int>>>adj;
vector<vector<int>>up,cnt;
vector<int>depth;
void dfs(int u,int parent){
    up[0][u]=parent;
    for(auto &neigh:adj[u]){
        int v=neigh.first;
        int w=neigh.second;
        if(v==parent) continue;
        depth[v]=depth[u]+1;
        for(int i=1;i<=26;i++) cnt[v][i]=cnt[u][i];
        cnt[v][w]++;
        dfs(v,u); 
    }
}

int get_kth_ances(int u,int k){
    for(int i=0;i<LOG;i++){
        if(k&(1<<i)){
            u=up[i][u];
            if(u==-1) break;
        }
    }
    return u;
}

int get_lca(int u,int v){
if(depth[u]<depth[v]) swap(u,v);
int diff=depth[u]-depth[v];
u=get_kth_ances(u,diff);
if(u==v) return u;
for(int k=LOG-1;k>=0;k--){
    if(up[k][u]!=up[k][v]){
        u=up[k][u];
        v=up[k][v];
    }
  }
  return up[0][u];
}

 int minOp(int u,int v){
 int lca=get_lca(u,v);
 int path_len=depth[u]+depth[v]-2*depth[lca];

 int max_freq=0;
 for(int w=1;w<=26;w++){
   int freq=cnt[u][w]+cnt[v][w]-2*cnt[lca][w];
   max_freq=max(max_freq,freq);
   }
   return path_len-max_freq;
 }

    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        N=n;
        LOG=15;
        depth.resize(n,0);
        cnt.resize(n,vector<int>(27,0));
        up.resize(LOG,vector<int>(n,-1));
        for(auto &e:edges){
            int u=e[0],v=e[1],w=e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        dfs(0,-1);
        // fill dp
        for(int k=1;k<LOG;k++){
            for(int u=0;u<n;u++){
                if(up[k-1][u]!=-1)
                  up[k][u]=up[k-1][up[k-1][u]];
            }
        }

      vector<int>res;
      for(auto &q:queries){
        res.push_back(minOp(q[0],q[1]));
      }
      return res;
    }
};