class Solution {
public:
    unordered_map<int,vector<int>>adj;
    long long f(int u,int n,vector<int>&baseTime){
        if(adj[u].empty()){
            return baseTime[u];
        }
        long long maxi=LLONG_MIN,mini=LLONG_MAX;
        for(auto &v:adj[u]){
           long long val=f(v,n,baseTime);
            maxi=max(maxi,val);
            mini=min(mini,val);
        }
        long long ownDuration=(long long)(maxi-mini)+baseTime[u];
        return (long long)maxi+ownDuration;
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        for(auto &e:edges){
            int u=e[0],v=e[1];
            adj[u].push_back(v);
        }
        return f(0,n,baseTime);
        
    }
};