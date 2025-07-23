long long t[100001][2];
typedef long long ll;
class Solution {
public:
ll f(int i,int parity,vector<int>&nums,int n){
    if(i>=n) return 0;
    if(t[i][parity]!=-1) return t[i][parity];
    ll sum=0ll;
    if(parity==0){
         sum=max((ll)nums[i]+f(i+1,1,nums,n),(ll)f(i+1,0,nums,n));
    }else{
         sum=max((ll)-nums[i]+f(i+1,0,nums,n),(ll)f(i+1,1,nums,n));
    }
    return t[i][parity]=sum;
}
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
      memset(t,-1,sizeof(t));
      return f(0,0,nums,n);
    }
};