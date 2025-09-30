class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<unsigned int>t(amount+1,0);
        t[0]=1;
        for(auto c:coins){
            for(int i=c;i<=amount;i++){ if(i-c<0) continue; t[i]+=t[i-c]; }
        }
        return t[amount];
    }
};