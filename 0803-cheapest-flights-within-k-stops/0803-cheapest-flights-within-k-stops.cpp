class Solution {
public:
int f(int n,vector<vector<pair<int,int>>>&adj,int src,int dst,int k){
    vector<int>t(n,INT_MAX);
    t[src]=0;
    int res=INT_MAX;
    queue<vector<int>>q;
    q.push({src,0,k});
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            auto pt=q.front();
            q.pop();
            int adj_node=pt[0];
            int wt=pt[1];
            int k=pt[2];
            if(k<0) continue;
            for(auto &vec:adj[adj_node]){
                int v=vec.first,w=vec.second;
                if(wt+w<t[v]){
                    t[v]=wt+w;
                    q.push({v,t[v],k-1});
                }
            }
        }
    }
    return t[dst];
}
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &f:flights){
            int u=f[0],v=f[1],p=f[2];
            adj[u].push_back({v,p});
        }
        int ans=f(n,adj,src,dst,k);
        return ans==INT_MAX?-1:ans;
    }
};