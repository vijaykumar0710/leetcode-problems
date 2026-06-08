class Solution {
public:
long long NEG=-1e14;
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n=nums.size();
        vector<long long>prefix(n+1,0);
        for(int i=0;i<n;i++) prefix[i+1]=prefix[i]+nums[i];
        vector<vector<long long>>dp(m+1,vector<long long>(n+1,NEG));
        for(int i=0;i<=n;i++) dp[0][i]=0;
        long long res=NEG;
        for(int k=1;k<=m;k++){
            deque<int>dq;
            for(int i=1;i<=n;i++){
                dp[k][i]=dp[k][i-1];
                int l_idx=i-r,r_idx=i-l;
                if(r_idx>=0){
                    long long val=dp[k-1][r_idx]+prefix[i]-prefix[r_idx];
                    while(!dq.empty() && (dp[k-1][dq.back()]+prefix[i]-prefix[dq.back()])<=val) 
                         dq.pop_back();
                    dq.push_back(r_idx);
                }
                while(!dq.empty() && dq.front()<l_idx) dq.pop_front();
                if(!dq.empty()){
                    int idx=dq.front();
                    dp[k][i]=max(dp[k][i],dp[k-1][idx]+prefix[i]-prefix[idx]);
                }
                res=max(res,dp[k][i]);
            }
        }
        return res;
    }
};