class Solution {
public:
int n;
int t[1001][1001];
int f(int rem,int j,vector<int>&nums){
if(j>=n) return nums[rem];
if(j==n-1) return max(nums[rem],nums[j]);
if(t[rem][j]!=-1) return t[rem][j];
int op1=max(nums[rem],nums[j])+f(j+1,j+2,nums);
int op2=max(nums[rem],nums[j+1])+f(j,j+2,nums);
int op3=max(nums[j],nums[j+1])+f(rem,j+2,nums);
return t[rem][j]=min({op1,op2,op3});
}
    int minCost(vector<int>& nums) {
        n=nums.size();
        memset(t,-1,sizeof(t));
        return f(0,1,nums);
    }
};