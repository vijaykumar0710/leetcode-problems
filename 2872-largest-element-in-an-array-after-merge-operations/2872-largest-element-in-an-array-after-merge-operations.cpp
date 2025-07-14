class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long max_sum=0;
        long long curr_sum=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=curr_sum) curr_sum+=nums[i];
            else{
                max_sum=max(max_sum,curr_sum);
                curr_sum=nums[i];
            }
        }
        max_sum=max(max_sum,curr_sum);
        return max_sum;
    }
};