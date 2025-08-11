class Solution {
public:
typedef long long ll;
const int M=1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<ll>power;
        vector<int>res;
        for(int i=0;i<32;i++){
            if(n&(1<<i)) power.push_back(1<<i);
        }
        for(auto &q:queries){
            long long pro=1;
            for(int i=q[0];i<=q[1];i++){
                pro=(pro*power[i])%M;
            }
             res.push_back(pro);
        }
        return res;
    }
};