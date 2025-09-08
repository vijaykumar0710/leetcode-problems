class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int n=piles.size(),max_takes=n/3,res=0,i=n-2;
        while(max_takes--) res+=piles[i],i-=2;
        return res;
    }
};