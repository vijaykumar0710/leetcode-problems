class Solution {
public:
int atMost(vector<int>& nums, int goal){
    int n=nums.size(),i=0,sum=0,subarray_cnt=0;
    for(int j=0;j<n;j++){
        sum+=nums[j];
        while(i<=j && sum>goal) sum-=nums[i++];
        subarray_cnt+=(j-i+1);
    }
     return subarray_cnt;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums,goal)-atMost(nums,goal-1);
    }
};