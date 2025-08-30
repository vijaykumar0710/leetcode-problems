class Solution {
public:
const int M=1e9+7;
vector<int>res;
    int countOrders(int n) {
        res.resize(n+1);
        if(n==1) return 1;
        res[1]=1;
        for(int i=2;i<=n;i++){
            int s=2*(i-1)+1;
            res[i]=1ll*((s*(s+1))/2)*res[i-1]%M;
        }
        return res[n]; 
    }
};