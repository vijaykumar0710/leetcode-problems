class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n=nums.size();
       long double pro=1;
        for(auto &num:nums) pro=1ll*pro*num;
        for(int mask=0;mask<(1<<n);mask++){
           long double s=1ll;
            for(int i=0;i<n;i++){
                if(mask&(1<<i))s=1ll*s*nums[i];
            }
           long double pro1=pro/s;
            if(pro1==target && s==target) return true;
        }
        return false;
    }
};