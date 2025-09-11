class Solution {
public:
vector<vector<int>>adj;
vector<int>value;
long long dfs(int u,int par){
    long long sum=0;
    bool isLeaf=true;
    for(auto &v:adj[u]){
        if(v==par) continue;
        isLeaf=false;
        sum+=dfs(v,u);
    }
    if(isLeaf) return value[u];
    return min<long long>(sum,value[u]);
}
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n=values.size();
        value=values;
        adj.assign(n,{});
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        long long rem=dfs(0,-1);
        long long total=accumulate(values.begin(),values.end(),0LL);
        return total-rem;
    }
};