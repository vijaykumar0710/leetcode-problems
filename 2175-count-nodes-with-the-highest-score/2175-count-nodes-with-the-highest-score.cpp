class Solution {
public:
vector<vector<int>>adj;
vector<int>subtree_size;
void dfs1(int node,int par){
    subtree_size[node]=1;
    for(auto &child:adj[node]){
        if(child==par) continue;
        dfs1(child,node);
        subtree_size[node]+=subtree_size[child];
    }
}
map<long long,long long>mp;
void dfs2(int node,int par){
   long long pro=1;
   for(auto &child:adj[node]){
    pro=1ll*pro*subtree_size[child];
   }
   mp[pro]++;
    for(auto &child:adj[node]){
        if(child==par) continue;
        
        int subtree_size_node=subtree_size[node];
        int subtree_size_child=subtree_size[child];

        subtree_size[node]-=subtree_size[child];
        subtree_size[child]+=subtree_size[node];

        dfs2(child,node);

        subtree_size[node]=subtree_size_node;
        subtree_size[child]=subtree_size_child;
    }
}
    int countHighestScoreNodes(vector<int>& parents) {
     int n=parents.size();
     adj.resize(n);
     subtree_size.resize(n);
     for(int i=1;i<n;i++){
         adj[parents[i]].push_back(i);
         adj[i].push_back(parents[i]);
     }
     dfs1(0,-1);
     dfs2(0,-1);
     return mp.rbegin()->second;
    }
};