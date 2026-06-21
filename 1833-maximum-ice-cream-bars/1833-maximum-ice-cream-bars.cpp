class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();
        sort(costs.begin(),costs.end());
        int iceCream=0;
        for(int i=0;i<n;i++){
            if(coins>=costs[i]){
                iceCream++;
                coins-=costs[i];
            }
        }
        return iceCream;
    }
};