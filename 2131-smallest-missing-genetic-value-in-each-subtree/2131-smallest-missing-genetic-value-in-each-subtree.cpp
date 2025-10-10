class Solution {
public:
unordered_map<int,vector<int>>adj;
vector<bool>seen;
int mex=1;
void dfs(int u,int par,vector<int>&nums){
if(seen[nums[u]]) return;
seen[nums[u]]=true;
for(auto v:adj[u]){
    if(v==par) continue;
    dfs(v,u,nums);
   }
}
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n=parents.size();
        seen.assign(100005,false);
        vector<int>res(n,1);
        for(int i=1;i<n;i++){
            adj[i].push_back(parents[i]);
            adj[parents[i]].push_back(i);
        }
        int pos=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==1) pos=i;
        }
        if(pos==-1) return res;
        int u=pos;
        while(u!=-1){
            dfs(u,parents[u],nums);
            while(seen[mex]) mex++;
            res[u]=mex;
            u=parents[u];
        }
      return res;  
    }
};