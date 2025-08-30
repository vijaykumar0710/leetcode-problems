class Solution {
public:
const int M=1e9+7;
    int countOrders(int n) { 
        int prev=1;
        for(int i=2;i<=n;i++){
            int s=2*(i-1)+1;
            prev=1ll*((s*(s+1))/2)*prev%M;
        }
        return prev; 
    }
};