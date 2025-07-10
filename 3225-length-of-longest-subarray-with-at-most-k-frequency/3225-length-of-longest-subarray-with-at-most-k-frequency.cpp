class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int i=0,len=0;
        int freq=0;
        for(int j=0;j<n;j++){
            mp[nums[j]]++;
            while(mp[nums[j]]>k){
                mp[nums[i]]--;
                i++;
            }
            len=max(len,j-i+1);
        }
        return len;
    }
};