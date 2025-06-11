class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<unsigned int>>t(n+1,vector<unsigned int>(amount+1,0));
        for(int i=0;i<=n;i++)
           t[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=amount;j++){
                if(coins[i-1]<=j){
                    t[i][j]=t[i-1][j]+t[i][j-coins[i-1]];
                }else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][amount];
    }
};