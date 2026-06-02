class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>res;
        map<int,int>mp;
        int i=0;
        for(int j=0;j<n;j++){
            mp[nums[j]]++;
            if(j-i+1>=k){
                int maxi=mp.rbegin()->first;
                res.push_back(maxi);
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
        }
        return res;
    }
};