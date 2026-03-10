class Solution {
public:
long long f(int l,int r,vector<int>&nums,int tar){
if(l==r) return nums[l]>0?1:0;
int mid=l+(r-l)/2;
long long left_cnt=f(l,mid,nums,tar);
long long right_cnt=f(mid+1,r,nums,tar);
vector<int>left_suffix,right_prefix;
long long curr=0LL;
for(int i=mid;i>=l;i--){
    curr+=nums[i];
    left_suffix.push_back(curr);
}
curr=0LL;
for(int i=mid+1;i<=r;i++){
    curr+=nums[i];
    right_prefix.push_back(curr);
}
sort(right_prefix.begin(),right_prefix.end());
long long cnt=0;
for(auto x:left_suffix){
    cnt+=right_prefix.end()-upper_bound(right_prefix.begin(),right_prefix.end(),-x);
}
return cnt+left_cnt+right_cnt;
}
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++) nums[i]==target?nums[i]=1:nums[i]=-1;
        return f(0,nums.size()-1,nums,target);
    }
};