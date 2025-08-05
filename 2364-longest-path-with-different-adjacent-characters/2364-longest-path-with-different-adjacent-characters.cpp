class Solution {
public:
vector<vector<int>>adj;
int res=0;
int dfs(int node,int par,string &s){ 
    int first_max=0,second_max=0;
    for(auto &child:adj[node]){
        if(child==par) continue;
       int dist=dfs(child,node,s);
        if(s[node]!=s[child]){
            if(dist>first_max){
                second_max=first_max;
                first_max=dist;
            }else if(dist>second_max){
                second_max=dist;
            }
        }
    }
  res=max(res,first_max+second_max+1);
  return first_max+1;
}
    int longestPath(vector<int>& parent, string s) {
        int n=s.size();
        adj.resize(n);
        for(int i=1;i<n;i++){
          adj[parent[i]].push_back(i);
          adj[i].push_back(parent[i]);
        }
        dfs(0,-1,s);
        return res;
    }
};