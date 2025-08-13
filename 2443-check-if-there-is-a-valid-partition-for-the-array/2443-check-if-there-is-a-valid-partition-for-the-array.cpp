class Solution {
public:
int t[100001];
bool f(int i,int n,vector<int>& nums){
   if(i>=n) return true;
   if(t[i]!=-1) return t[i];

   bool res=false;

   if(i+1<n && nums[i]==nums[i+1]){ 
      res=(res || f(i+2,n,nums));
   }

   if(i+2<n && ((nums[i]==nums[i+1] && nums[i+1]==nums[i+2]) || ((nums[i]-nums[i+1]==-1) && (nums[i+1]-nums[i+2]==-1)))){
      res=(res || f(i+3,n,nums));
   }

   return t[i]=res;
}
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        memset(t,-1,sizeof(t));
        return f(0,n,nums);
    }
};