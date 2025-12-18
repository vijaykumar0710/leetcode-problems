class Solution {
public:
    long long maxProfit(vector<int>& p, vector<int>& st, int k) {
        int n=p.size();
        vector<long long>prefix1(n),prefix2(n);
        prefix1[0]=p[0]*st[0];
        prefix2[0]=p[0];
        for(int i=1;i<n;i++){
            prefix1[i]=prefix1[i-1]+(p[i]*st[i]);
            prefix2[i]=prefix2[i-1]+p[i];
        }
        long long res=prefix1[n-1];
        for(int i=0;i<=n-k;i++){
            long long a=i-1<0?0:prefix1[i-1];
            long long b=prefix2[i+k-1]-prefix2[i-1+k/2];
            long long c=prefix1[n-1]-prefix1[i+k-1];
            res=max(res,(a+b+c));
        }
        return res;
    }
};