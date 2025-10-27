class Solution {
public:
    int uniquePaths(int m, int n) {
        int N=m+n-2,r=n-1;
        double res=1;
        for(int i=1;i<=min(r,N-r);i++) res=res*(N-i+1)/i;
        return res;
    }
};