class Solution {
public:
int change(int target,vector<int>&coin){
    int n=coin.size();
    vector<vector<int>>t(n+1,vector<int>(target+1,0));
    for(int i=0;i<=n;i++)
       t[i][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=target;j++){
            if(coin[i-1]<=j){
                t[i][j]=t[i-1][j]+t[i][j-coin[i-1]];
            }else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][target];
}
    vector<int> findCoins(vector<int>& numWays) {
       int n = numWays.size();
        vector<int> coins;
        for(int i=1;i<=n;i++){
            int ways = change(i,coins);
            if(ways+1==numWays[i-1]) coins.push_back(i);
            else if(ways!=numWays[i-1]) return {};
        }
        return coins;
    }
};