class Solution {
public:
void solve(int mask,int n,int &ans){
    if(mask==(1<<n)-1){
        ans++;
        return;
    }
    int pos=__builtin_popcount(mask)+1;
    for(int num=1;num<=n;num++){
        if(!(mask&(1<<(num-1))) && (pos%num==0 || num%pos==0)){
            solve(mask|(1<<(num-1)),n,ans);
        }
    }
}
    int countArrangement(int n) {
        int ans=0;
        solve(0,n,ans);
        return ans;
    }
};