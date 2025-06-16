class Solution {
public:
 unordered_map<int,vector<int>>adj;
 vector<int>res;
 vector<int>subtree_size;
 vector<int>dp;

void dfs1(int node,int parent){
  subtree_size[node]=1;
  dp[node]=0;
  for(auto &child:adj[node]){
    if(child==parent) continue;
    dfs1(child,node);
    subtree_size[node]+=subtree_size[child];
    dp[node]+=(dp[child]+subtree_size[child]);
    }
}

void dfs2(int node,int parent){
    res[node]=dp[node];
    for(auto &child:adj[node]){
        if(child==parent) continue;

    int dp_node=dp[node],dp_child=dp[child];
    int subtree_size_node=subtree_size[node],subtree_size_child=subtree_size[child];
    
     dp[node]-=(dp[child]+subtree_size[child]);
     subtree_size[node]-=subtree_size[child];

      dp[child]+=(dp[node]+subtree_size[node]);
     subtree_size[child]+=subtree_size[node];

     dfs2(child,node);

     dp[node]=dp_node;
     dp[child]=dp_child;
     subtree_size[node]=subtree_size_node;
     subtree_size[child]=subtree_size_child;
    }
}
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        res.resize(n);
        subtree_size.resize(n);
        dp.resize(n);

        for(auto &edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs1(0,-1);
        dfs2(0,-1);
        return res;
    }
};