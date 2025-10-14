class Solution {
public:
bool isValid(vector<int>&t,vector<int>&nums,int k){
int n=nums.size();
for(int i=0;i+2*k<=n;i++)if(t[i+k-1]>=k && t[i+2*k-1]>=k) return true;
return false;
}
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>t(n,1);
        for(int i=1;i<n;i++) t[i]=nums[i-1]<nums[i]?t[i-1]+1:1;
        int l=1,r=n/2,k=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(t,nums,mid)){ k=mid,l=mid+1;}
            else r=mid-1;
        }
        return k;
    }
};