class Solution {
public:
int t[1<<15];
int solve(int mask,int n){
    int ans=0;
    if(mask==(1<<n)-1){
        return 1;
    }
    if(t[mask]!=-1) return t[mask];
    int pos=__builtin_popcount(mask)+1;
    for(int num=1;num<=n;num++){
        if(!(mask&(1<<(num-1))) && (pos%num==0 || num%pos==0)){
            ans+=solve(mask|(1<<(num-1)),n);
        }
    }
    return t[mask]=ans;
}
    int countArrangement(int n) {
        memset(t,-1,sizeof(t));
        return solve(0,n);
    }
};