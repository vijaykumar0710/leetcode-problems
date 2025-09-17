class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long res=0;
        unordered_map<int,int>mp;
        for(auto &x:nums2) mp[x*k]++;
        for(auto &y:nums1){
            for(int i=1;i<=sqrt(y);i++){
                if(y%i==0){
                    if(mp.count(i)) res+=mp[i];
                    if(i!=y/i &&  mp.count(y/i)) res+=mp[y/i];
                }
            }
        }
        return res;
    }
};