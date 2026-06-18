class Solution {
public:
    int countVowelStrings(int n) {
        return (long long)((n+4)*(n+3)*(n+2)*(n+1))/24;
    }
};