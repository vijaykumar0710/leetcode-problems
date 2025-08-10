class Solution {
public:
const int M=1e9+7;
    int minimumPossibleSum(int n, int target) {
        long long sum=0;
        int k=target/2;
        if(n<=k) return (1ll*(n%M)*((n+1)%M)/2)%M;
        long long len=0;
        for(int i=1;i<=k;i++){
           sum+=i;
           len++;
        }
        long long j=target;
        while(len!=n){
           sum+=j;
           len++;
           j++;
        }
        return sum%M;
    }
};