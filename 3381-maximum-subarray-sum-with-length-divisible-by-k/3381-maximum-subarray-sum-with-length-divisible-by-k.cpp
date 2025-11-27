class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>pref(n,0);
        pref[0]=nums[0];
        for(int i=1;i<n;i++) pref[i]=(long long)pref[i-1]+nums[i];
        long long res=LLONG_MIN;
        unordered_map<int,long long>mp;
        mp[0]=0;
        for(int i=1;i<=n;i++){
            int r=i%k;
            if(mp.count(r)){
                res=max(res,pref[i-1]-mp[r]);
            }
            if(!mp.count(r)) mp[r]=pref[i-1];
            mp[r]=min(mp[r],pref[i-1]);
        }
        return res;
    }
};