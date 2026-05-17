class Solution {
public:
    int arrangeCoins(int n) {
        int l=0,r=n;
        int res=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            int x=mid;
            int y=mid+1;
            if((x%2)==0) x=x/2;
            else y=y/2;
            long long coins=1LL*x*y;
            if(coins<=n){
                res=mid;
                l=mid+1;
            }else r=mid-1;
        }
        return res;
    }
};