class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int res=INT_MAX;
        int i=0,sum=0;
       for(int j=0;j<n;j++){
        sum+=nums[j];
        while(j-i+1>=l && j-i+1<=r){
          if(sum>0) res=min(res,sum);
           sum-=nums[i];
           i++;
        }
       }
       return res==INT_MAX?-1:res;
    }
};