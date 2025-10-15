class Solution {
public:
vector<vector<int>>adj;
unordered_map<int,int>mp;
long long cnt=0;
void dfs(int u,int p,vector<int>& nums){
 if(p!=-1) mp[nums[p]]++;
  for(auto &v:adj[u]){
    if(v==p) continue;
    dfs(v,u,nums);
  }
  for(auto [x,freq]:mp){
    long long num=1LL*x*nums[u];
    long long y=sqrt(num);
    if(y*y==num) cnt+=freq;
  }
  if(p!=-1) mp[nums[p]]--;
  if(p!=-1 && mp[nums[p]]==0) mp.erase(nums[p]);
 return;
}
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
    adj.assign(n,{});
    for(auto &e:edges){
    adj[e[0]].push_back(e[1]);
    adj[e[1]].push_back(e[0]);
    }
    dfs(0,-1,nums);
     return cnt;   
    }
};