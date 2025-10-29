class Solution {
public:
    int smallestNumber(int n) {
        int msb=0,res=0;
        while(n>0) msb++,n/=2;
        for(int i=0;i<msb;i++)res|=(1<<i);
        return res;
    }
};