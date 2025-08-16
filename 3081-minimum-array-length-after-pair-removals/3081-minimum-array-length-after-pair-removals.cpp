class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
         int l=0;int r=n/2;
         while(l<n/2 && r<n){
            if(nums[l]<nums[r]){
                cnt+=2;
                l++;
            }
            r++;
         }
        return n-cnt;
    }
};