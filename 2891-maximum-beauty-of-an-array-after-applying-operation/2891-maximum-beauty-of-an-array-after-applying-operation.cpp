class Solution {
public:
bool can_achieve(int m,int k,vector<int>&nums){
    int n=nums.size();
    for(int i=0;i<=(int)n-m;i++){
        if(nums[i+m-1]-nums[i]<=2*k) return true;
    }
    return false;
}
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=1,r=n;
        int res=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(can_achieve(mid,k,nums)){
                res=max(res,mid);
                l=mid+1;
            }else r=mid-1;
        }
        return res;
    }
};