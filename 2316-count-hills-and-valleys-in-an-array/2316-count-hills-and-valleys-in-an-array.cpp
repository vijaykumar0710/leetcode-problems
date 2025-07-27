class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        vector<int>group;
        int cnt=1;
        int i=1;
        for(;i<n;i++){
            if(nums[i]==nums[i-1]) cnt++;
            else{
                group.push_back(nums[i-1]);
                cnt=1;
            }
        }
        group.push_back(nums[i-1]);
        int res=0;
        if(group.size()<3) return res;
        for(int i=1;i<group.size()-1;i++){
            if((group[i-1]>group[i] && group[i+1]>group[i]) || (group[i-1]<group[i] && group[i+1]<group[i]))
              res++;
        }
        return res;
    }
};