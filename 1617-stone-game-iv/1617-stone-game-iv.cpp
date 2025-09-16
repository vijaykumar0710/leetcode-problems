class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool>t(n+1,false);
        for(int i=1;i<=n;i++){
            int sq=sqrt(i);
            for(int j=1;j<=sq;j++){
                if(!t[i-(j*j)]){
                    t[i]=true;
                    break;
                }
            }
        }
        return t[n]; // O(n*sqrt(n))
    }
};