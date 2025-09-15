class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        long long res=0;
        for(auto &x:nums){
            int g1=gcd(x,k);
            for(auto &[g2,freq]:mp){
                if((1LL*g1*g2)%k==0) res+=freq;
            }
            mp[g1]++;
        }
        return res;
    }
};