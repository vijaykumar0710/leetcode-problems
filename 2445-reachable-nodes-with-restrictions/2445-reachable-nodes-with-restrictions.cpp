class Solution {
public:
int dfs(int u,unordered_map<int,vector<int>>&adj,unordered_set<int>&st){
    int res=1;
    for(auto &v:adj[u]){
        if(st.count(v)) continue;
        st.insert(v);
        res+=dfs(v,adj,st);
    }
    return res;
}
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_map<int,vector<int>>adj;
        unordered_set<int>st(restricted.begin(),restricted.end());
        for(auto &e:edges){ adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]); }
        st.insert(0);
        return dfs(0,adj,st);
    }
};