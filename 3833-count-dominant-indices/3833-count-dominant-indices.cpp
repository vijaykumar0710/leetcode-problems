class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n=nums.size();
        int sum=nums[n-1];
        int cnt=0;
        for(int i=n-2;i>=0;i--){
          sum+=nums[i];
          if(nums[i]>(double)sum/(n-i))
          cnt++;
        }
        return cnt;
    }
};