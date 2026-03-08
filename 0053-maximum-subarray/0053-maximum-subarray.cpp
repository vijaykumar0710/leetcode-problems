class Solution {
public:
int f(int l,int r,vector<int>&nums){
    if(l==r) return nums[l];
    int mid=l+(r-l)/2;
    int left=f(l,mid,nums);
    int right=f(mid+1,r,nums);
    int left_cross_sum=INT_MIN;
    int curr_sum=0;
    for(int i=mid;i>=l;i--){
        curr_sum+=nums[i];
        left_cross_sum=max(left_cross_sum,curr_sum);
    }
    curr_sum=0;
    int right_cross_sum=INT_MIN;
    for(int i=mid+1;i<=r;i++){
        curr_sum+=nums[i];
        right_cross_sum=max(right_cross_sum,curr_sum);
    }
    int cross_sum=left_cross_sum+right_cross_sum;
    return max({cross_sum,left,right});
}
    int maxSubArray(vector<int>& nums) {
        return f(0,nums.size()-1,nums);
    }
};