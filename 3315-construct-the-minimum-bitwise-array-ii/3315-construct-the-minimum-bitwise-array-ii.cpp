class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
          if(nums[i]==2) ans.push_back(-1);
          else{
            int mask=~(((nums[i]+1)&~nums[i])>>1);
            ans.push_back((mask&nums[i]));
          } 
        }
        return ans;
    }
};