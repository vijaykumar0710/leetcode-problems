class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++){
            total=(total+nums[i])%p;
        }
        if(total==0) return 0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int pref=0,res=n;
        for(int i=0;i<n;i++){
           pref=(pref+nums[i])%p;
           int req=(pref-total+p)%p;
           if(mp.count(req)){
            res=min(res,i-mp[req]);
           }
           mp[pref]=i;
        }
        return res==n?-1:res;
    }
};