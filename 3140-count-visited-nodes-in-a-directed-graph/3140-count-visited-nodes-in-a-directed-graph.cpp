class Solution {
public:
vector<int>res;
void dfs(int u,vector<int>& edges,vector<bool>&visited,vector<bool>&inRecursion){
    visited[u]=true;
    inRecursion[u]=true;
    int v=edges[u];
    if(!visited[v]){
        dfs(v,edges,visited,inRecursion);
    }else{
        if(inRecursion[v]){
            int x=v,cycle_len=1;
            while(edges[x]!=v){cycle_len++,x=edges[x];}
            x=v;
            res[x]=cycle_len;
            while(edges[x]!=v){x=edges[x],res[x]=cycle_len;}
        }
    }
    if(res[u]==0) res[u]=1+res[v];
    inRecursion[u]=false;
}
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n=edges.size();
        res.assign(n,0);
        vector<bool>visited(n,false),inRecursion(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]) dfs(i,edges,visited,inRecursion);
        }
        return res;
    }
};