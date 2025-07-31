class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        int min_pos=-1,max_pos=-1,bad_idx=-1;
        long long cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]<minK || nums[i]>maxK) bad_idx=i;
            if(nums[i]==minK) min_pos=i;
            if(nums[i]==maxK) max_pos=i;
            cnt+=max(0,min(min_pos,max_pos)-bad_idx);
        }
        return cnt;
    }
};