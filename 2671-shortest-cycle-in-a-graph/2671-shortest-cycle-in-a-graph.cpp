class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        int res=INT_MAX;
        for(auto &e:edges){
           int u=e[0],v=e[1];
           adj[u].push_back(v);
           adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){ 
           vector<int>dist(n,-1);
           queue<int>q;
           q.push(i);
            dist[i]=0;
           while(!q.empty()){
            int u=q.front();
            q.pop();
           for(auto &v:adj[u]){
                 if(dist[v]==-1){
                    dist[v]=dist[u]+1;
                    q.push(v);
                 }else if(dist[v]>=dist[u]){
                    res=min(res,dist[u]+dist[v]+1);
                 }
             }
           }
        }
        return res==INT_MAX?-1:res;
    }
};