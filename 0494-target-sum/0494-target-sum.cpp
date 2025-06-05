class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();

        int totalSum=accumulate(nums.begin(),nums.end(),0);
        if((target+totalSum)%2==1 || target+totalSum<0) return 0;

        int s1=(target+totalSum)/2;
        
        vector<vector<int>>t(n+1,vector<int>(s1+1,0));
        for(int i=0;i<=n;i++){
            t[i][0]=1;
        }

        for(int i=1;i<=n;i++){
            for(int j=0;j<=s1;j++){
                if(nums[i-1]<=j) t[i][j]=t[i-1][j-nums[i-1]]+t[i-1][j];
                else t[i][j]=t[i-1][j];
            }
        }
        return t[n][s1];
    }
};