class Solution {
public:
int t[201][10001];
bool solve(vector<int>&nums,int target,int n){
    if(target==0) return true;
    if(n==0) return false;
    if(t[n][target]!=-1) return t[n][target];
    if(nums[n-1]<=target){
        t[n][target]=solve(nums,target-nums[n-1],n-1) || solve(nums,target,n-1);
    }else{ 
       t[n][target]=solve(nums,target,n-1);
    }
    return t[n][target];
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1) return false;
        memset(t,-1,sizeof(t));
        return solve(nums,sum/2,n);
    }
};