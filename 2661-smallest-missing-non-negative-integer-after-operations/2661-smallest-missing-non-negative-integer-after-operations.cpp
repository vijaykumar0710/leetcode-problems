class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int>mp;
        for(auto x:nums) mp[(x%value+value)%value]++;
        int mex=0;
        while(true){
            if(mp[mex%value]==0) return mex;
            else mp[mex%value]--;
            mex++;
        }
    }
};