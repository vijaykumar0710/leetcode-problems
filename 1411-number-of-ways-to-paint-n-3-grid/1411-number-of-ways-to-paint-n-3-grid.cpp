class Solution {
public:
const int M=1e9+7;
    int numOfWays(int n) {
        long long two=6,three=6;
        n--;
        while(n--){
        long long nxttwo=(2*three+3*two)%M;
        three=(2*two+2*three)%M;
        two=nxttwo;
        }
        return (two+three)%M;
    }
};