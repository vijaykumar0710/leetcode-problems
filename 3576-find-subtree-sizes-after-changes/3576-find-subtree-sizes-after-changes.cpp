class Solution {
public:
unordered_map<char,vector<int>>mp;
vector<int>subtree_size;
void dfs1(int u,unordered_map<int,vector<int>>&adj,vector<int>&parent,string &s){
    if(mp.count(s[u])){
        parent[u]=mp[s[u]].back();
    }
    mp[s[u]].push_back(u);
    for(auto &v:adj[u]){
        dfs1(v,adj,parent,s);
    }
    mp[s[u]].pop_back();
    if(mp[s[u]].size()==0) mp.erase(s[u]);
}
int dfs2(int u,unordered_map<int,vector<int>>&adj1){
   int size=1;
   for(auto &v:adj1[u]){
      size+=dfs2(v,adj1);
   }
   subtree_size[u]=size;
   return size;
}
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=parent.size();
        unordered_map<int,vector<int>>adj;
     for(int i=1;i<n;i++){
        adj[parent[i]].push_back(i);
       }
        dfs1(0,adj,parent,s);
    unordered_map<int,vector<int>>adj1;
      for(int i=1;i<n;i++){
       adj1[parent[i]].push_back(i);
    }
    subtree_size.resize(n,0);
     dfs2(0,adj1);
     return subtree_size;
    }
};