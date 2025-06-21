class Solution {
public:
bool isValid(vector<int>& nums,int mid,int n){
    long long prefix_sum=0;
    int i=0;
    while(i<n){
        prefix_sum+=nums[i];
        if(prefix_sum>1LL*mid*(i+1)) return false;
        i++;
    }
    return true;
}
    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
        int l=*min_element(nums.begin(),nums.end());
        int r=*max_element(nums.begin(),nums.end());
        int res=r+1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(nums,mid,n)){
                res=min(res,mid);
                r=mid-1;
            }else l=mid+1;
        }
        return res;
    }
};