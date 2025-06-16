class Solution {
public:
vector<vector<int>>adj;
vector<int>subtree_size;
vector<long long>res;

void dfs1(int node,int parent){
    subtree_size[node]=1;
    for(auto &child:adj[node]){
        if(child==parent) continue;
        dfs1(child,node);
        subtree_size[node]+=subtree_size[child];
    }
}

void dfs2(int node,int parent){
  long long product=1;
  for(auto &child:adj[node]){
    product=1LL*product*subtree_size[child];
  }
   res[node]=product;

  for(auto &child:adj[node]){
      if(child==parent) continue;
      int subtree_size_node=subtree_size[node],subtree_size_child=subtree_size[child];

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
        res.resize(n);
        for(int i=1;i<n;i++){
            adj[parents[i]].push_back(i);
            adj[i].push_back(parents[i]);
        }
        dfs1(0,-1);
        dfs2(0,-1);
        long long maxi=*max_element(res.begin(),res.end());
        int cnt=0;
        for(auto &x:res){
            if(x==maxi)
               cnt++;
        }
        return cnt;
    }
};