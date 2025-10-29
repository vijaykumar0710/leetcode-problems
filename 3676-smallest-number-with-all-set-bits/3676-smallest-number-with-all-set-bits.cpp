class Solution {
public:
    int smallestNumber(int n) {
        int res=0;
        int i=0;
        while(n>0){
            res|=(1<<i);
            n/=2;
            i++;
        }
        return res;
    }
};