class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max_xor=0,mask=0;
        for(int i=31;i>=0;i--){
            mask|=(1<<i);
            unordered_set<int>prefixes;
        //    We are only interested in the bits up to the current position because 
        //    we are building the maximum XOR bit by bit from MSB to LSB.
        //    Lower bits (after i-th) don’t matter yet, so we ignore them.
            for(auto &num:nums) prefixes.insert(num&mask);
             int candidate=max_xor|(1<<i); // “Can I make the current bit 1 without violating what I already have in higher bits?”
             for(auto p:prefixes){
                if(prefixes.count(p^candidate)){
                    max_xor=candidate;
                    break;
                }
             }
        }
        return max_xor;
    }
};