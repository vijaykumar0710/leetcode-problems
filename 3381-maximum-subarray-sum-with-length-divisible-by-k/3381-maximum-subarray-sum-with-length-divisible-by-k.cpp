class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>pref(n,0);
        pref[0]=nums[0];
        for(int i=1;i<n;i++) pref[i]=(long long)pref[i-1]+nums[i];
        long long res=LLONG_MIN;
        for(int st=0;st<k;st++){
            long long currSum=0;
            int i=st;
            while(i<n && i+k-1<n){
                int j=i+k-1;
                long long subSum=pref[j]-(i>0?pref[i-1]:0);
                currSum=max(subSum,subSum+currSum);
                res=max(res,currSum);
                i+=k;
            }
        }
        return res;
    }
};