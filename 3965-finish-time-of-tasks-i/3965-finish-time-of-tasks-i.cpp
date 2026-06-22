class Solution {
public:
unordered_map<int,vector<int>>adj;
long long f(int u,vector<int>& baseTime){
    if(adj[u].empty()) return baseTime[u];
    long long maxi=LONG_MIN,mini=LLONG_MAX;
    for(auto v:adj[u]){
        long long x=f(v,baseTime);
        maxi=max(maxi,x);
        mini=min(mini,x);
    }
    long long ownDuration=(long long)maxi-mini+baseTime[u];
    return (long long)maxi+ownDuration;
}
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        for(auto e:edges){
            int u=e[0],v=e[1];
            adj[u].push_back(v);
        }
        return f(0,baseTime);
    }
};