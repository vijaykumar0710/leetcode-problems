class Solution {
public:
int n;
bool f(int i,vector<int>&nums, double target, double s1, double s2){
if(i>=n){
    return (s1==target && s2==target);
   }
   bool flag=false;
   for(int idx=i;idx<n;idx++){
    s1=1ll*s1*nums[idx];
    flag|=f(idx+1,nums,target,s1,s2);
    s1=1ll*(s1/nums[idx]);
    s2=1ll*s2*nums[idx];
    flag|=f(idx+1,nums,target,s1,s2);
    s2=1ll*(s2/nums[idx]);
   }
   return flag;
}
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        n=nums.size();
        return f(0,nums,target,1,1);
    }
};