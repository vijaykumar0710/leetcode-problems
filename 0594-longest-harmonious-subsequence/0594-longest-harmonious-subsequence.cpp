class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
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
        int len=0;
        for(int i=1;i<group.size();i++){
            if(group[i].first-group[i-1].first==1)
                len=max(len,(group[i].second+group[i-1].second));
        }
        return len;
    }
};