class Solution {
public:
int dijkstra(int src,int n, vector<int>& prices, unordered_map<int,vector<vector<int>>>&adj){
vector<long long>res(n,1e9);
vector<int>vec(n,1e9);
priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq1;
res[src]=0;
vec[src]=0;
pq1.push({0,src});
pq.push({0,src});
while(!pq1.empty()){
    int u=pq1.top().second;
    int c=pq1.top().first;
    pq1.pop();
    for(auto &neigh:adj[u]){
        int v=neigh[0],cost=neigh[1];
        int new_cost=c+cost;
        if(new_cost<vec[v]){
            pq1.push({new_cost,v});
            vec[v]=new_cost;
        }
    } 
  }
while(!pq.empty()){
    int u=pq.top().second;
    long long c=pq.top().first;
    pq.pop();
    for(auto &neigh:adj[u]){
        int v=neigh[0],cost=neigh[1],tax=neigh[2];
        long long new_cost=c+1LL*cost*tax;
        if(new_cost<res[v]){
            pq.push({new_cost,v});
            res[v]=new_cost;
        }
    } 
  }
  long long ans=INT_MAX;
  for(int i=0;i<n;i++){
    ans=min(ans,(long long)res[i]+vec[i]+prices[i]);
  }
  return ans;
}
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        unordered_map<int,vector<vector<int>>>adj;
        for(auto &r:roads){
            int u=r[0],v=r[1],cost=r[2],tax=r[3];
            adj[u].push_back({v,cost,tax});
            adj[v].push_back({u,cost,tax});
        }
       vector<int>res(n);
       for(int i=0;i<n;i++)
        res[i]=dijkstra(i,n,prices,adj);
       return res;
    }
};