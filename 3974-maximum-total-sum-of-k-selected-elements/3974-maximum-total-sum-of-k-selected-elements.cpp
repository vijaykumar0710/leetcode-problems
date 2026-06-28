class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long res=0;
        sort(nums.rbegin(),nums.rend());
        for(int i=0;i<k;i++){
          if(mul>0)res+=1LL*nums[i]*mul;
          else res+=nums[i];
            mul--;
        }
        return res;
    }
};