class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>mp1,mp2;
        for(auto n:nums) mp1[n]++;
        for(auto [n,freq]:mp1) mp2[freq]++;
        for(auto n:nums){
            if(mp2[mp1[n]]==1) return n;
        }
        return -1;
    }
};