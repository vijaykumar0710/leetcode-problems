class Solution {
public:
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
vector<vector<pair<int,int>>>adj;
    int minCost(int n, vector<vector<int>>& edges) {
        adj.assign(n,{});
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],2*e[2]});
        }
       vector<int>res(n+1,INT_MAX);
       res[0]=0; pq.push({0,0});
       while(!pq.empty()){
         int cost=pq.top().first,u=pq.top().second;pq.pop();
         for(auto [v,c]:adj[u]){
            if(c+cost>=res[v]) continue;
            res[v]=c+cost; pq.push({c+cost,v});
         }
      }
      return res[n-1]==INT_MAX?-1:res[n-1];
    }
};