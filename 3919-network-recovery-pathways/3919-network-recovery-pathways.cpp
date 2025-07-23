typedef long long ll;
class Solution {
public:
bool dijkstra(vector<vector<pair<ll,ll>>>&adj,int mid,vector<bool>&online,long long k){
    int n=online.size();
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    vector<long long>res(n,LLONG_MAX/4);
    pq.push({0,0});
    res[0]=0;
    while(!pq.empty()){
        int wt=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(wt>res[node]) continue;
        if(node==n-1) return res[n-1]<=k;
        for(auto &v:adj[node]){
            int adjNode=v.first;
            int w=v.second;
            if(online[adjNode] && w>=mid){
                if((ll)wt+w<res[adjNode]){
                    res[adjNode]=(ll)wt+w;
                    pq.push({(ll)w+wt,adjNode});
                }
            }
        }
    }
   return res[n-1]<=k;
}
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
         vector<vector<pair<ll,ll>>>adj(n);
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            adj[u].push_back({v,wt});
        }
        int res=-1;
        int l=0,r=1e9;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(dijkstra(adj,mid,online,k)){
                res=mid;
                l=mid+1;
            }else r=mid-1;
        }
        return res;
    }
};