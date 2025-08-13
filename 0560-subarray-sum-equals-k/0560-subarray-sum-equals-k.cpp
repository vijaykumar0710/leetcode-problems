class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int sum=0,cnt=0;
        for(int i=0;i<n;i++){
          sum+=nums[i];
          if(sum==k) cnt++;
          if(mp.count(sum-k)) cnt+=mp[sum-k];
          mp[sum]++;
        }
        return cnt;
    }
};