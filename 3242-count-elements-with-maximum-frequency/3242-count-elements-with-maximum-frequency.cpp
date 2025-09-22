class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxi=0;
        for(auto &num:nums){
            mp[num]++;
            maxi=max(maxi,mp[num]);
        }
        int cnt=0;
        for(auto [num,freq]:mp){
            if(freq==maxi){
                cnt+=freq;
            }
        }
        return cnt;
    }
};