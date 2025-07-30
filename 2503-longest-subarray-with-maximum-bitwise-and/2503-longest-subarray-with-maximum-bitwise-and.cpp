class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>group;
        int cnt=1;
        int i=1;
       for(;i<n;i++){
        if(nums[i]==nums[i-1])
            cnt++;
        else{
           group.push_back({nums[i-1],cnt});
            cnt=1;
          }
       }
       group.push_back({nums[i-1],cnt});
       sort(group.begin(),group.end());
       return group[group.size()-1].second;
    }
};