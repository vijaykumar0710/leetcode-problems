class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>suff(n,0);
        for(int i=n-2;i>=0;i--){
            if(nums[i]==nums[i+1]) suff[i]=suff[i+1];
            else suff[i]=n-i-1;
        }
        int res=0;
        for(int i=0;i<n;i++){
           if(suff[i]>=k) res++;
        }
        return res;
    }
};