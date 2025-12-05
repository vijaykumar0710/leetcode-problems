class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int pre=0,cnt=0;
        for(int i=0;i<n;i++){
            pre+=nums[i];
            if(pre==k) cnt++;
            if(mp.find(pre-k)!=mp.end()){
                cnt++;
            }
            mp[pre]++;
        }
        return cnt;
    }
};