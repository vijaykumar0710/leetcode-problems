class Solution {
public:
void f(int l,int r,vector<int>&nums){
    if(l>=r) return;
    int mid=l+(r-l)/2;
    f(l,mid,nums);
    f(mid+1,r,nums);
    int i=l,j=mid+1;
    vector<int>res;
    while(i<=mid && j<=r){
        if(nums[i]<nums[j]){
            res.push_back(nums[i++]);
        }else{
            res.push_back(nums[j++]);
        }
    }
    while(i<=mid) res.push_back(nums[i++]);
    while(j<=r)  res.push_back(nums[j++]);
    for(int k=0;k<res.size();k++) nums[k+l]=res[k];
}
    vector<int> sortArray(vector<int>& nums) {
        f(0,nums.size()-1,nums);
        return nums;
    }
};