class Solution {
public:
int t[1001][51];
int f(int i,int n,int k,vector<int>&nums,vector<int>&prefix_sum){
    if(k==1){
        return prefix_sum[nums.size()]-prefix_sum[i];
    }
    if(t[i][k]!=-1) return t[i][k];
    int res=INT_MAX;
    for(int j=i;j<=n-k;j++){
        int sum=prefix_sum[j+1]-prefix_sum[i];
        int temp=max(sum,f(j+1,n,k-1,nums,prefix_sum));
        res=min(res,temp);
    }
    return t[i][k]=res;
}
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefix_sum(n+1,0);
        for(int i=0;i<n;i++){
            prefix_sum[i+1]=prefix_sum[i]+nums[i];
        }
        memset(t,-1,sizeof(t));
       return f(0,n,k,nums,prefix_sum);
    }
};