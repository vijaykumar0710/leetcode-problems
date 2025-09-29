const int INF=1e9;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>t(amount+1,INF);
        t[0]=0;
        for(int i=1;i<=amount;i++){
            for(auto coin:coins){ if(i-coin<0) continue; t[i]=min(t[i],1+t[i-coin]); }
        }
        return t[amount]==INF?-1:t[amount];
    }
};