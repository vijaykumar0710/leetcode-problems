const int M=1e9+7;
typedef long long ll;

class Solution {
public:
    ll power(ll base,ll exp){
        base%=M;
        ll res=1;
        while(exp>0){
            if(exp&1) res=(res*base)%M;
            base=(base*base)%M;
            exp>>=1;
        }
        return res;
    }

    int countPartitions(vector<int>& nums, int k) {
        int n=nums.size();
        ll total=0;
        for(int x:nums) total += x;
        
        if(total < 2LL*k) return 0;

        vector<vector<ll>> t(n+1, vector<ll>(k,0));
        t[0][0] = 1; // base case: empty subset, sum=0

        for(int i=1;i<=n;i++){
            for(int j=0;j<k;j++){
                if(j >= nums[i-1]) {
                    t[i][j] = (t[i-1][j]+t[i-1][j-nums[i-1]]) % M;
                }else t[i][j]=t[i][j]+t[i-1][j];
            }
        }

        ll bad = 0;
        for(int j=0;j<k;j++) bad = (bad + t[n][j]) % M;

        ll total_ways = power(2,n);
        ll ans = (total_ways - 2*bad) % M;
        if(ans < 0) ans += M;
        return ans;
    }
};