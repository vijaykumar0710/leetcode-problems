class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>t(amount+1,1e9);
        t[0]=0;
        for(int i=1;i<=amount;i++){
            for(auto c:coins){
                if(i-c<0) continue;
                t[i]=min(t[i],1+t[i-c]);
            }
        }
        return t[amount]==1e9?-1:t[amount];
    }
};