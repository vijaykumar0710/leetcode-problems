int t[2005][2005][3];
const int M=1e9+7;
class Solution {
public:
int N,L,R;
int f(int len,int num,int flag){
 if(len==N) return 1;
 if(t[len][num][flag]!=-1) return t[len][num][flag];
 int ans=0;
 if(flag){
    if(num<R)
    ans=(ans+f(len+1,num+1,0)+f(len,num+1,1))%M;
 }else{
    if(num>L)
    ans=(ans+f(len+1,num-1,1)+f(len,num-1,0))%M;
 }
 return t[len][num][flag]=ans;
}
    int zigZagArrays(int n, int l, int r) {
        N=n,L=l,R=r;
        int res=0;
        memset(t,-1,sizeof(t));
        for(int i=l;i<=r;i++){
            res=(res+f(1,i,1))%M;
            res=(res+f(1,i,0))%M;
        }
        return res;
    }
};