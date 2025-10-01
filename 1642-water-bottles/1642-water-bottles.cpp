class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res=numBottles;
        while(numBottles>=numExchange){
            res+=(numBottles/numExchange);
            int rem=numBottles%numExchange;
            numBottles=(numBottles/numExchange)+rem;
        }
        return res;
    }
};