class Solution {
public:
bool dijkstra(int n,vector<vector<pair<int,int>>>&adj,int src, int tar, int k,int mid){
priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
vector<int>t(n,INT_MAX);
t[src]=0;
pq.push({0,0,src});
while(!pq.empty()){
    auto node=pq.top();
    pq.pop();
    int u=node[2],lmt=node[1];
    if(lmt>k) continue;
    for(auto &v:adj[u]){
        if(v.second>mid){
            if(t[v.first]>lmt+1){
                pq.push({v.second,lmt+1,v.first});
                t[v.first]=lmt+1;
            }
        }
        else{
           if(t[v.first]>lmt){
            pq.push({v.second,lmt,v.first});
            t[v.first]=lmt;
           }
        }
    }
 } 
 return t[tar]<=k;
}
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        vector<vector<pair<int,int>>>adj(n);
        int r=0;
        for(auto &e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
            r=max(r,e[2]);
        }
      int l=0;
      int res=-1;
      while(l<=r){
        int mid=l+(r-l)/2;
        if(dijkstra(n,adj,source,target,k,mid)){
             res=mid;
             r=mid-1;
        }else l=mid+1;
      }
      return res;
    }
};