class Solution {
public:
vector<int>subtree_xor,inTime,outTime;
int dfs(int u,int par,int &timer,vector<int>&nums,vector<vector<int>>&adj){
  int xor_val=nums[u];
  inTime[u]=timer;
  timer++;
  for(auto &v:adj[u]){
    if(v!=par){ 
    int child_xor=dfs(v,u,timer,nums,adj);
     xor_val^=child_xor;
    }
  }
  outTime[u]=timer;
  timer++;
  subtree_xor[u]=xor_val;
  return xor_val;
}
bool isAncestor(int u,int v){
   return inTime[u]<=inTime[v] && outTime[u]>=outTime[v];
}
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        subtree_xor.resize(n);
        inTime.resize(n);
        outTime.resize(n);
        vector<vector<int>>adj(n);
        for(auto &e:edges){adj[e[0]].push_back(e[1]); adj[e[1]].push_back(e[0]); }
        int timer=0;
        dfs(0,-1,timer,nums,adj);
        int score=INT_MAX;
        for(int u=1;u<n;u++){ // 0 is root so start at 1
            for(int v=u+1;v<n;v++){
                int xor1,xor2,xor3;
                if(isAncestor(u,v)){
                  xor1=subtree_xor[v];
                  xor2=subtree_xor[u]^xor1;
                  xor3=subtree_xor[0]^xor1^xor2;
                }else if(isAncestor(v,u)){
                  xor1=subtree_xor[u];
                  xor2=subtree_xor[v]^xor1;
                  xor3=subtree_xor[0]^xor1^xor2;
                }else{
                  xor1=subtree_xor[u];
                  xor2=subtree_xor[v];
                  xor3=subtree_xor[0]^xor1^xor2;
                }
                int mini=min({xor1,xor2,xor3});
                int maxi=max({xor1,xor2,xor3});
                score=min(score,maxi-mini);
            }
        }
        return score;
    }
};