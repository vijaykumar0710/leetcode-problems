class Solution {
public:
bool f(int u,int col,vector<int>&color,unordered_map<int,vector<int>>&adj){
color[u]=col;
for(auto &v:adj[u]){
    if(color[v]==col) return false;
    if(color[v]==-1){
    if(!f(v,1-col,color,adj)) return false;
    }
}
return true;
}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>>adj;
        for(auto e:dislikes){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
        }
        vector<int>color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(!f(i,0,color,adj)) return false;
            }
        }
        return true;
    }
};