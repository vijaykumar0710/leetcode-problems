typedef long long ll;
class Solution {
public:
bool isValid(vector<int>& nums,vector<ll>prefix_sum,int mid,long long k){
    if(mid==0) return true;
  int n=nums.size();
  int i=0,j=mid-1;
  while(j<n){
    ll target_idx=(i+j)/2;
    ll target=nums[target_idx];

    ll left_op=0;
    ll right_op=0;

    if(target_idx==0) left_op=0;
    else left_op=abs(((target_idx-i)*target)-(prefix_sum[target_idx-1]-(i>0?prefix_sum[i-1]:0)));
    right_op=abs(((j-target_idx)*target)-(prefix_sum[j]-prefix_sum[target_idx]));

    if(left_op+right_op<=k) return true;
    i++,j++;
  }
  return false;
}
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<ll>prefix_sum(n,0);
        prefix_sum[0]=nums[0];
        for(int i=1;i<n;i++) prefix_sum[i]=prefix_sum[i-1]+nums[i];
        int len=0;
        int l=0,r=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(nums,prefix_sum,mid,k)){
                len=mid;
                l=mid+1;
            }else r=mid-1;
        }
        return len;
    }
};