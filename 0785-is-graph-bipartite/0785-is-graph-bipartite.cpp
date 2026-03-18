class Solution {
public:
bool f(int u,int col,vector<int>&color,vector<vector<int>>& graph){
    color[u]=col;
    for(auto &v:graph[u]){
        if(color[v]==col) return false;
        if(color[v]==-1){
            if(!f(v,1-col,color,graph)) return false;
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
         vector<int>color(n,-1);
         for(int i=0;i<n;i++){
            if(color[i]==-1){
            if(!f(i,1,color,graph)) return false;
            }
         }
         return true;
    }
};