class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
      int n=nums.size();
      if(n==1) return nums[0];
      vector<long long>t;
      for(int i=0;i<n;i++) t.push_back(nums[i]);
      if(colors[0]!=colors[1]) t[1]+=nums[0];
      for(int i=2;i<n;i++){
        if(colors[i]==colors[i-1]) t[i]+=max(t[i-2],(t[i-1]-nums[i-1]));
        else t[i]+=max(t[i-1],t[i-2]);
      }
      return max(t[n-1],t[n-2]);
    }
};