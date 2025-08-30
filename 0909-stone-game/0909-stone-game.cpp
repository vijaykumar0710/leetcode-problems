class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int xor_val=0;
        for(auto &p:piles) xor_val^=p;
        return xor_val!=0;
    }
};