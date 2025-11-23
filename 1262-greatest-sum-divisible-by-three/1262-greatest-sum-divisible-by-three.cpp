class Solution {
public:
int n;
int t[40001][3];
int f(int i,vector<int>& nums,int sum){
    if(i>=n){
        if(sum%3==0) return sum;
        return INT_MIN; 
    }
    if(t[i][sum]!=-1) return t[i][sum]; 
    int skip=f(i+1,nums,sum);
    int take=INT_MIN;
    int new_sum=(sum+nums[i])%3;
    int next=f(i+1,nums,new_sum);
    if(next!=INT_MIN) take=nums[i]+next;
    return t[i][sum]=max(skip,take);
}
    int maxSumDivThree(vector<int>& nums) {
      n=nums.size();
      sort(nums.begin(),nums.end());
      memset(t,-1,sizeof(t));
      return f(0,nums,0);  
    }
};