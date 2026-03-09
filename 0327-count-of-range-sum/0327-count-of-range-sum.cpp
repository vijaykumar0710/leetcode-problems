class Solution {
public:
void merge(int l,int r,int mid,vector<long long>&nums){
    int i=l,j=mid+1;
    vector<long long>res;
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
int f(int l,int r,int lower,int upper,vector<long long>&prefix){
    if(l>=r) return 0;
    int mid=l+(r-l)/2;
    int left_cnt=f(l,mid,lower,upper,prefix);
    int right_cnt=f(mid+1,r,lower,upper,prefix);
    int j=mid+1;
    int k=mid+1;
    int cross_cnt=0;
    for(int i=l;i<=mid;i++){
    while(j<=r && prefix[j]-prefix[i]<lower) j++;
    while(k<=r && prefix[k]-prefix[i]<=upper) k++;
    cross_cnt+=(k-j);
    }
    merge(l,r,mid,prefix);
    return cross_cnt+left_cnt+right_cnt;
}
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        vector<long long>prefix(n+1,0);
        for(int i=0;i<n;i++) prefix[i+1]=prefix[i]+nums[i];
        return f(0,n,lower,upper,prefix);
    }
};