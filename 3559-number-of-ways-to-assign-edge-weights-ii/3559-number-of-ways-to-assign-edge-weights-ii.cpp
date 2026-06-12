class Solution {
public:
const int M=1e9+7;
const int LOG=20;
vector<int>depth;
vector<vector<int>>up;
void dfs(int node,int par, unordered_map<int, vector<int>>& adj){
    depth[node]=depth[par]+1;
    up[node][0]=par;
    for(int i=1;i<LOG;i++){
        up[node][i]=up[up[node][i-1]][i-1];
    }
    for(int child:adj[node]){
     if(child!=par){
        dfs(child,node,adj);
     }
    }
}

int LCA(int u,int v){
if(depth[u]<depth[v]) swap(u,v);
for(int i=LOG-1;i>=0;i--){
    if(depth[u]-(1<<i)>=depth[v]) u=up[u][i];
}
if(u==v) return u;
for(int i=LOG-1;i>=0;i--){
    if(up[u][i]!=up[v][i]){
        u=up[u][i];
        v=up[v][i];
    }
}
return up[u][0];
}

int get_dist(int u,int v){
    int lca=LCA(u,v);
    return depth[u]+depth[v]-2*depth[lca];
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
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n=edges.size()+1;
        unordered_map<int, vector<int>>adj;
        depth.resize(n+1);
        up.resize(n+1,vector<int>(LOG));
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(1,0,adj);
        vector<int>res;
        for(auto &q:queries){
            int u=q[0],v=q[1];
            if(u==v) res.push_back(0);
            else{
                int d=get_dist(u,v);
                long long ans=mod_pow(2,d-1);
                res.push_back(ans);
            }
        }
        return res;
    }
};