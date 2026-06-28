class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long total_sum=0;
        sort(nums.rbegin(),nums.rend());
        for(int i=0;i<k;i++){
            if(mul>0) total_sum+=1LL*nums[i]*mul;
            else total_sum+=nums[i];
            mul--;
        }
        return total_sum;
    }
};