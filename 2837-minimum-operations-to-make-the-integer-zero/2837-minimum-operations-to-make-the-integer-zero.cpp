class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int k=1;k<=60;k++){
           long long num=1ll*num1-1ll*k*(num2);
           if(num>=k && __builtin_popcountll(num)<=k)
               return k;
        }
        return -1;
    }
};