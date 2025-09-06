class Solution {
public:
typedef long long ll;
ll cal_cost(vector<int>& nums, vector<int>& cost,int target){
    int n=nums.size();
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=(ll)abs(nums[i]-target)*cost[i];
    }
    return sum;
}
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n=nums.size();
        ll ans=LLONG_MAX;
        int l=*min_element(nums.begin(),nums.end());
        int r=*max_element(nums.begin(),nums.end());
        while(l<=r){
            int mid=l+(r-l)/2;
            ll cost1=cal_cost(nums,cost,mid);
            ll cost2=cal_cost(nums,cost,mid+1);
            ans=min(ans,cost1);
            if(cost2>cost1){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans==LLONG_MAX?0:ans;
    }
};