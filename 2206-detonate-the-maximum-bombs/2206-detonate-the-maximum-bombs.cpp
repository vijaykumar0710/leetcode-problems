class Solution {
public:
typedef long long ll;
void dfs(vector<vector<int>>&adj,int u,vector<bool>&visited){
  visited[u]=true;
  for(auto &v:adj[u]){
    if(!visited[v]){
        dfs(adj,v,visited);
    }
  }
}
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        sort(bombs.begin(), bombs.end());
        vector<vector<int>>adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
               // if(i==j) continue;
                ll x1 = bombs[i][0];
                ll y1 = bombs[i][1];
                ll r1 = bombs[i][2];

                ll x2 = bombs[j][0];
                ll y2 = bombs[j][1];
                ll r2 = bombs[j][2];

                ll d = (x1 - x2) * (x1 - x2)+(y1 - y2) * (y1 - y2);
                if (r1*r1 >= d) adj[i].push_back(j);
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            vector<bool>visited(n,false);
            dfs(adj,i,visited);
            int cnt=0;
            for(auto x:visited){
                if(x==true) cnt++;
                res=max(res,cnt);
            }
        }
        return res;
    }
};