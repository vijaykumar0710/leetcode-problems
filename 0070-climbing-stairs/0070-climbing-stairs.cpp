class Solution {
public:
int t[46];
int f(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    if(t[n]!=-1) return t[n];
    return t[n]=f(n-1)+f(n-2);
}
    int climbStairs(int n) {
        memset(t,-1,sizeof(t));
        return f(n);
    }
};