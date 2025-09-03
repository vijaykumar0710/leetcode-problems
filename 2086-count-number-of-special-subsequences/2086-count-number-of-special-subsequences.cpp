const int M=1e9+7;
class Solution {
public:
int n;
int t[100001][4];
int f(int i,int k,vector<int>&nums){
  if(i==n) return k==2;
  if(t[i][k+1]!=-1) return t[i][k+1];
  int cnt=0;
  cnt=(cnt+f(i+1,k,nums))%M;
  if(nums[i]==0 && k<=0) cnt=(cnt+f(i+1,0,nums))%M;
  else if(nums[i]==1 && (k==0 || k==1)) cnt=(cnt+f(i+1,1,nums))%M;
  else if(nums[i]==2 && (k==1 || k==2)) cnt=(cnt+f(i+1,2,nums))%M;
  return t[i][k+1]=cnt%M;
}
    int countSpecialSubsequences(vector<int>& nums) {
        n=nums.size();
        memset(t,-1,sizeof(t));
        return f(0,-1,nums);
    }
};