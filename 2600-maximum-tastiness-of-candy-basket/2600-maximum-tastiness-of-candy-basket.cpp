class Solution {
public:
bool isValid(vector<int>&nums,int k,int mid){
    int cnt=1,n=nums.size(),last=nums[0];
    for(int i=1;i<n;i++){
       if(nums[i]-last>=mid){ cnt++; last=nums[i];}
       if(cnt>=k) return true;
    }
    return cnt>=k;
}
    int maximumTastiness(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int res=0;
        int l=0,r=nums[n-1]-nums[0];
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(nums,k,mid)){res=mid; l=mid+1;}
            else r=mid-1;
        }
        return res;
    }
};