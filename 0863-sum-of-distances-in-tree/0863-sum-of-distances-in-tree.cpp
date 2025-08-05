class Solution {
public:
vector<vector<int>>adj;
vector<int>subtree_size,dp,res;
void dfs1(int node,int par){
    subtree_size[node]=1;
    dp[node]=0;
    for(auto &child:adj[node]){
        if(child==par) continue;
        dfs1(child,node);
        subtree_size[node]+=subtree_size[child];
        dp[node]+=(subtree_size[child]+dp[child]);
    }
}
void dfs2(int node,int par){
    res[node]=dp[node];
    for(auto &child:adj[node]){
        if(child==par) continue;

        int subtree_size_node=subtree_size[node];
        int dp_node=dp[node];

        subtree_size[node]-=subtree_size[child];
        dp[node]-=(dp[child]+subtree_size[child]);

        subtree_size[child]+=subtree_size[node];
        dp[child]+=(dp[node]+subtree_size[node]);
       
       dfs2(child,node);

       subtree_size[node]=subtree_size_node;
       dp[node]=dp_node;
    }
}
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
       adj.resize(n);
       subtree_size.resize(n);
       dp.resize(n);
       res.resize(n);

       for(auto &e:edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
       }

       dfs1(0,-1);
       dfs2(0,-1);

       return res;
    }
};