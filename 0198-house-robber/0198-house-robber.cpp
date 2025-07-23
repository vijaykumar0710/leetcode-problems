class Solution {
public:
int t[101];
int f(int i,vector<int>&nums){
    if(i<0) return 0;
    if(i==0) return nums[i];
    if(t[i]!=-1) return t[i];
    int take=nums[i]+f(i-2,nums);
    int skip=f(i-1,nums);
    return t[i]=max(take,skip);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(t,-1,sizeof(t));
        return f(n-1,nums);
    }
};