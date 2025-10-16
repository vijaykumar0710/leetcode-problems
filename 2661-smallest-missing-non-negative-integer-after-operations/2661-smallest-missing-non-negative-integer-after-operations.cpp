class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int>mp;
        for(auto x:nums) mp[(x%value+value)%value]++;
        for(int i=0;i<=nums.size();i++){
         if(mp[i%value]==0) return i;
         else mp[i%value]--;
       }
       return 0;
    }
};