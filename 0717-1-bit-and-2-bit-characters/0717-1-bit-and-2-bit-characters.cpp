class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        if(n==1) return true;
        if(bits[n-2]==1 && (bits[n-1]==0 || bits[n-1]==1)) return false;
        return true;
    }
};