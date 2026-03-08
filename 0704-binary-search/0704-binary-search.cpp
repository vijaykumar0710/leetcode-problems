class Solution {
public:
int f(int l,int r,int tar,vector<int>&nums){
    if(l>r) return -1;
    int mid=l+(r-l)/2;
    if(nums[mid]==tar) return mid;
    if(nums[mid]>tar){
        return f(l,mid-1,tar,nums);
    }else{
        return f(mid+1,r,tar,nums);
    }
}
    int search(vector<int>& nums, int target) {
        return f(0,nums.size()-1,target,nums);
    }
};