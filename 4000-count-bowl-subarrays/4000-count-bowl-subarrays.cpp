class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n=nums.size();
        long long res=0;
        vector<int>right_max(n),left_max(n);
        right_max[0]=nums[0],left_max[n-1]=nums[n-1];
        for(int i=1;i<n-1;i++){
            right_max[i]=max(right_max[i-1],nums[i]);
            left_max[n-i-1]=max(left_max[n-i],nums[n-i-1]);
        }
        for(int i=1;i<n-1;i++) if(nums[i]<min(right_max[i],left_max[i])) res++;
        return res;
    }
};