class Solution {
public:
const int M=1e9+7;
int t[3002][1001];
int f(int st,int end,int k){
    if(k==0){
       return st==end;
    }
    if(t[st+1001][k]!=-1) return t[st+1001][k];
    int cnt=0;
    cnt=(cnt+f(st-1,end,k-1))%M;
    cnt=(cnt+f(st+1,end,k-1))%M;
    return t[st+1001][k]=cnt%M;
}
    int numberOfWays(int startPos, int endPos, int k) {
        memset(t,-1,sizeof(t));
        return f(startPos,endPos,k);
    }
};