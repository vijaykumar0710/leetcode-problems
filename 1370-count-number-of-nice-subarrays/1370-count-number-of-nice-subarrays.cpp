class Solution {
public:
int atMost(vector<int>&nums,int k){
    int n=nums.size(),i=0,odd_cnt=0,subarray_cnt=0;
    for(int j=0;j<n;j++){
        if(nums[j]%2==1) odd_cnt++;
        while(odd_cnt>k){
            if(nums[i]%2==1) odd_cnt--;
            i++;
        }
        subarray_cnt+=(j-i+1);
    }
      return subarray_cnt;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
    }
};