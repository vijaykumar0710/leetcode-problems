const int MOD=1e9+7;
class Solution {
public:
int get_mask(int val){
    int mask=0;
    while(val){
        int d=val%10;
        if(mask&(1<<d)) return -1;
        mask|=(1<<d);
        val/=10;
    }
    return mask;
}
void dfs(int u,int par,vector<int>&vals,unordered_map<int,vector<int>>&adj,vector<int>&mask,vector<unordered_map<int,int>>&dp,long long &ans){
    if(mask[u]!=-1) dp[u][mask[u]]=vals[u];
    for(auto &v:adj[u]){
        if(v==par) continue;
        dfs(v,u,vals,adj,mask,dp,ans);
          //agar leaf node hua toh yaha enter nahi karega
        unordered_map<int,int>new_dp=dp[u];
        for(auto &[mask1,sum1]:dp[u]){
            for(auto &[mask2,sum2]:dp[v]){
                if((mask1&mask2)==0){
                    int new_mask=mask1|mask2;
                    new_dp[new_mask]=max(new_dp[new_mask],sum1+sum2);
                }
            }
        }
        //without parent merging(parent contains duplicate)
        for(auto &[mask2,sum2]:dp[v]){
            new_dp[mask2]=max(new_dp[mask2],sum2);
        }
        dp[u]=move(new_dp);
    }
    int best=0;
    for(auto &[mask,sum]:dp[u]){
        best=max(best,sum);
    }
    ans=(ans+best)%MOD;
}
    int goodSubtreeSum(vector<int>& vals, vector<int>& par) {
        int n=vals.size();
        unordered_map<int,vector<int>>adj;
        for(int i=1;i<n;i++){
         adj[i].push_back(par[i]);
         adj[par[i]].push_back(i);
        }
        vector<int>mask(n);
        for(int i=0;i<n;i++){
            mask[i]=get_mask(vals[i]);
        }
        vector<unordered_map<int,int>>dp(n);
        long long ans=0;
        dfs(0,-1,vals,adj,mask,dp,ans);
        return ans;
    }
};