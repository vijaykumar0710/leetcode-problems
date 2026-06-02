class Solution {
public:
long long t[100005][5];
long long f(int i,int sign,vector<int>& nums,int n){
if(i>=n) return 0;
if(t[i][sign+2]!=-1) return t[i][sign+2];
return t[i][sign+2]=nums[i]*sign+max(f(i+1,1,nums,n),f(i+1,-1*sign,nums,n));
}
    long long maximumTotalCost(vector<int>& nums) {
        int n=nums.size();
        memset(t,-1,sizeof(t));
        return f(0,1,nums,n);
    }
};