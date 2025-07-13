class Solution {
public:
typedef pair<int,int>pii;
int prims_algo(int n,unordered_map<int,vector<pair<int,int>>>&adj){
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    int totalCost=0;
    pq.push({0,0});
    vector<bool>inMST(n,false);
    while(!pq.empty()){
      int cost=pq.top().first;
      int node=pq.top().second;
      pq.pop();
      if(inMST[node]==true) continue;
      inMST[node]=true;
       totalCost+=cost;
      for(auto &neigh:adj[node]){
        int v=neigh.first;
        int wt=neigh.second;
        if(!inMST[v]) pq.push({wt,v});
      }
    }
    return totalCost;
}
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
              int cost=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
              adj[i].push_back({j,cost});
              adj[j].push_back({i,cost});
            }
        }
        return prims_algo(n,adj);
    }
};