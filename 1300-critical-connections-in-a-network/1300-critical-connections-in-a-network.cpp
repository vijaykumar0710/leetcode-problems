class Solution {
public:
vector<vector<int>>adj,res;
vector<int>inTime,lowTime;
vector<bool>vis;
int timer=0;
void dfs(int u,int par){
vis[u]=true;
inTime[u]=lowTime[u]=timer;
timer++;
for(auto &v:adj[u]){
    if(v==par) continue;
     if(!vis[v]){
       dfs(v,u);
       lowTime[u]=min(lowTime[u],lowTime[v]);
       if(inTime[u]<lowTime[v]) res.push_back({u,v});
     }else lowTime[u]=min(lowTime[u],lowTime[v]);
   }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.assign(n,{}),inTime.resize(n,0),lowTime.resize(n,0),vis.assign(n,false);
        for(auto &e:connections){ adj[e[0]].push_back(e[1]); adj[e[1]].push_back(e[0]); }
        dfs(0,-1);
        return res;
    }
};