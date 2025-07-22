class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int i=0;
        long long max_sum=0,curr_sum=0;
        for(int j=0;j<n;j++){
            mp[nums[j]]++;
            curr_sum+=nums[j];
            while(mp[nums[j]]>1){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(mp[nums[i]]);
                curr_sum-=nums[i];
                i++;
            }
            max_sum=max(curr_sum,max_sum);
        }
        return max_sum;
    }
};