class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==target) nums[i]=1;
            else nums[i]=-1;
        }
        vector<int>prefix(n+1);
        prefix[0]=0;
        for(int i=1;i<=n;i++){
         prefix[i]=prefix[i-1]+nums[i-1];
        }
        int res=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<i;j++){
                if(prefix[j]<prefix[i]) res++;
            }
        }
        return res;
    }
};