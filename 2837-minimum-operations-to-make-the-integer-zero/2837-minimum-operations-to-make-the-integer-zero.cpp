class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int k=0;k<=60;k++){
            long long x=1ll*num1-1ll*k*(num2);
            if(x>=k && __builtin_popcountll(x)<=k)
              return k;
        }
        return -1;
    }
};