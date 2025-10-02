class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int res=numBottles,empty=numBottles;
        while(empty>=numExchange){ res++; empty=(empty-numExchange)+1; numExchange++; }
        return res;
    }
};