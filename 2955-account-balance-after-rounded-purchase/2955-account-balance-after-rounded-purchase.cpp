class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
     int x=purchaseAmount;
     return 100-floor(((x+5)/10)*10);
    }
};