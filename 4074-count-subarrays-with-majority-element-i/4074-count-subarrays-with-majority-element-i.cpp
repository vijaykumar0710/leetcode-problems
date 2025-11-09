class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i] = (nums[i]==target ? 1 : -1);
        }
        
        vector<long long> pref(n+1);
        pref[0]=0;
        for(int i=1;i<=n;i++){
            pref[i] = pref[i-1] + nums[i-1];
        }
        
        // coordinate compress
        vector<long long> comp = pref;
        sort(comp.begin(),comp.end());
        comp.erase(unique(comp.begin(),comp.end()),comp.end());
        
        auto getid=[&](long long x){
            return lower_bound(comp.begin(),comp.end(),x)-comp.begin()+1;
        };
        
        int m=comp.size();
        vector<long long> fen(m+1,0);
        
        auto update=[&](int i){
            for(;i<=m;i+=i&-i) fen[i]++;
        };
        auto query=[&](int i){
            long long s=0;
            for(;i>0;i-=i&-i) s+=fen[i];
            return s;
        };
        
        long long ans=0;
        for(int i=0;i<=n;i++){
            int id = getid(pref[i]);
            ans += query(id-1); // all prefix smaller
            update(id);
        }
        return ans;
    }
};