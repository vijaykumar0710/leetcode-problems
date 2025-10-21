class Solution {
public:
int f(vector<int>&nums,int target,int k,int op){
    int n=nums.size(),cnt=0;
    for(int i=0;i<n;i++){
        if(nums[i]==target){
            cnt++;
            continue;
        }
        int left=nums[i]-k,right=nums[i]+k;
        if(op>0){
          if(left<=target && right>=target){
            cnt++;
            op--;
          }
        }
    }
    return cnt;
}
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n=nums.size(),res=0;
        sort(nums.begin(),nums.end());
        int l=nums[0]-k,r=nums[n-1]+k;
        for(int t=l;t<=r;t++){
            res=max(res,f(nums,t,k,numOperations));
        }
        return res;
    }
};