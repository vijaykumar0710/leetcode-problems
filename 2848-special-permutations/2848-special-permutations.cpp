class Solution {
public:
const int M=1e9+7;
    int specialPerm(vector<int>& nums) {
        int n=nums.size();
        int N=1<<n;
        vector<vector<int>>dp(N,vector<int>(n,0));
        for(int i=0;i<n;i++) dp[1<<i][i]=1;
        for(int mask=1;mask<N;mask++){
            for(int last=0;last<n;last++){
                //check whether last is present or not in mask if not then skip
                if(!(mask&(1<<last))) continue;
                for(int i=0;i<n;i++){
                    //check whether it used(present in mask) or not if it is used then skip
                    if((mask&(1<<i))) continue;
                    if(nums[i]%nums[last]==0 || nums[last]%nums[i]==0){ 
                    int newMask=mask|(1<<i);
                    dp[newMask][i]=(dp[newMask][i]+dp[mask][last])%M;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=(ans+dp[N-1][i])%M;
        }
        return ans;
    }
};