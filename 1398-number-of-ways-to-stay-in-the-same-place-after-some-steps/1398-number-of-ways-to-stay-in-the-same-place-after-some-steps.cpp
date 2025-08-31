class Solution {
public:
int n;
const int M=1e9+7;
int t[501][501];
int f(int steps,int arrLen){
    if(steps==0){
        return arrLen==0;
    }
    if(t[steps][arrLen]!=-1) return t[steps][arrLen];
    int cnt=0;
    cnt=(cnt+f(steps-1,arrLen))%M;
    if(arrLen>0) cnt=(cnt+f(steps-1,arrLen-1))%M;
    if(arrLen<n) cnt=(cnt+f(steps-1,arrLen+1))%M;
    return t[steps][arrLen]=cnt%M;
}
    int numWays(int steps, int arrLen) {
        n=arrLen-1;
        memset(t,-1,sizeof(t));
     return f(steps,0);  
    }
};