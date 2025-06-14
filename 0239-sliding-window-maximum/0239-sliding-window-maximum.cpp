class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
         map<int,int,greater<int>>desc_mp;
         vector<int>res;
         int i=0;
        for(int j=0;j<n;j++){
            desc_mp[nums[j]]++;
            if(j-i+1>=k){
             res.push_back(desc_mp.begin()->first);
             desc_mp[nums[i]]--;
             if(desc_mp[nums[i]]==0) desc_mp.erase(nums[i]); 
             i++;  
            }
        }
        return res;
    }
};