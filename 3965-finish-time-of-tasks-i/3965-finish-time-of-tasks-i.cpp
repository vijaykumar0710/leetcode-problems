class Solution {
public:
    unordered_map<int,vector<int>>adj;
    void f(int u,int n,vector<int>&baseTime,vector<long long>&res){
        if(adj[u].empty()){
            res[u]=baseTime[u];
            return;
        }
        long long maxi=LLONG_MIN,mini=LLONG_MAX;
        for(auto &v:adj[u]){
            f(v,n,baseTime,res);
            maxi=max(maxi,res[v]);
            mini=min(mini,res[v]);
        }
        long long ownDuration=(long long)(maxi-mini)+baseTime[u];
        res[u]=(long long)maxi+ownDuration;
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        for(auto &e:edges){
            int u=e[0],v=e[1];
            adj[u].push_back(v);
        }
        vector<long long>res(n,0);
        f(0,n,baseTime,res);
        return (long long)res[0];
    }
};