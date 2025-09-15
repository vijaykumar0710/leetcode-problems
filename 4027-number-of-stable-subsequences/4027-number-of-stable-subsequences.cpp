const int M=1e9+7;
class Solution {
public:
int n;
int t[100001][3][4];
int f(int i,int parity,int len,vector<int>&nums){
   if(i>=n) return 1;
   if(t[i][parity+1][len]!=-1) return t[i][parity+1][len];
   int skip=f(i+1,parity,len,nums)%M;
   int take=0;
   if(len<2 || nums[i]%2!=parity){
    int new_parity=nums[i]%2;
    int new_len = (new_parity == parity ? len + 1 : 1);
    take=(take+f(i+1,new_parity,new_len,nums))%M;
   }
   return t[i][parity+1][len]=(skip+take)%M;
}
    int countStableSubsequences(vector<int>& nums) {
        n=nums.size();
        memset(t,-1,sizeof(t));
        return f(0,-1,0,nums)-1;
    }
};