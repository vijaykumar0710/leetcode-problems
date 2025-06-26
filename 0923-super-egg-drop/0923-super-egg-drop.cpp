class Solution {
public:
int t[101][10001];
int solve(int eggs,int floors){
    if(eggs==1 || floors==1 || floors==0) return floors;
    if(t[eggs][floors]!=-1) return t[eggs][floors];
    int l=1,h=floors;
    int min_moves=INT_MAX;;
    while(l<=h){
        int mid=l+(h-l)/2;
        int egg_break=solve(eggs-1,mid-1);
        int egg_not_break=solve(eggs,floors-mid);
        if(egg_break>egg_not_break) //egg break so search below
             h=mid-1;
        else l=mid+1;
        int worst_case=max(egg_break,egg_not_break)+1;
        min_moves=min(min_moves,worst_case);
    }
    return t[eggs][floors]=min_moves;
}
    int superEggDrop(int k, int n) {
        memset(t,-1,sizeof(t));
        return solve(k,n);
    }
};