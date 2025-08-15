class TreeAncestor {
public:
int N;
int LOG=20;
vector<vector<int>>adj;
vector<vector<int>>up;
void dfs(int u,int p){
    up[0][u]=p;
    for(auto &v:adj[u]){
    if(u!=v) dfs(v,u);
    }
}
    TreeAncestor(int n, vector<int>& parent) {
        N=n;
        up.assign(LOG,vector<int>(n+1,-1));
        adj.resize(n);
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        dfs(0,-1);
        for(int k=1;k<LOG;k++){
            for(int u=1;u<=N;u++){
                if(up[k-1][u]!=-1)
                  up[k][u]=up[k-1][up[k-1][u]];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<LOG;i++){
            if(k&(1<<i)){
                node=up[i][node];
                if(node==-1) break;
            }
        }
        return node;
    }
};