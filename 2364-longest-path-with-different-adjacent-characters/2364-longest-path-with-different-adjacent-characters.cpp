class Solution {
public:
int ans=0;
int dfs(int u,int par,vector<vector<int>>&adj,string &s){
   int first_max=0,second_max=0;
   for(auto &v:adj[u]){
    if(v==par) continue;
    int children=dfs(v,u,adj,s);
    if(s[u]!=s[v]){
        if(children>first_max){
            second_max=first_max;
            first_max=children;
        }else if(children>second_max){
            second_max=children;
        }
     }
   }
   ans=max(ans,(1+first_max+second_max));
   return first_max+1;
}
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }
        dfs(0, -1, adj, s);
        return ans;
    }
};
