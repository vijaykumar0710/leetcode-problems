typedef long long ll;
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
       int n=nums.size();
       vector<vector<ll>>t(n+1,vector<ll>(2,0));
       for(int i=1;i<=n;i++){
        t[i][0]=max(nums[i-1]+t[i-1][1],t[i-1][0]);
        t[i][1]=max(-nums[i-1]+t[i-1][0],t[i-1][1]);
       }
       return max(t[n][0],t[n][1]);
    }
};