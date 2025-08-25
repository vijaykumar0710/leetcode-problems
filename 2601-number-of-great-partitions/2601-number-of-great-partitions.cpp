const int M=1e9+7;
typedef long long ll;
class Solution {
public:
int n;
ll t[1001][1001];
ll f(int i,ll sum,vector<int>&nums,int k){
    if(sum>=k) return 0;
    if(i>=n) return 1;
    if(t[i][sum]!=-1) return t[i][sum];
    ll cnt=0ll;
    cnt+=f(i+1,sum+nums[i],nums,k);
    cnt+=f(i+1,sum,nums,k);
    return t[i][sum]=cnt%M;
}
ll power(ll base,ll exp){
   base%=M;
   ll res=1;
   while(exp>0){
    if(exp%2==1) res=(1ll*base*res)%M;
    base=(1ll*base*base)%M;
    exp/=2;
   }
   return res%M;
}
    int countPartitions(vector<int>& nums, int k) {
        n=nums.size();
        ll total=0ll;
        for(int i=0;i<n;i++){
            total=(ll)(total+nums[i])%M;
        }
        if(total<2*k) return 0ll;
        memset(t,-1,sizeof(t));
        int y=f(0,0,nums,k);
        ll total_ways=power(2,n);
        ll x=(total_ways-2*y+M)%M;
        return x;
    }
};