class Solution {
public:
    long long countCommas(long long n) {
        long long res=0;
        long long base=1000;
        while(n>=base){
          res+=(n-base+1);
          base*=1000;
    }
    return res;
    }
};