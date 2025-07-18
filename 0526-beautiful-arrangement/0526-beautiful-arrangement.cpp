class Solution {
public:
void solve(int pos,vector<int>&used,int n,int &ans){
    if(pos>n){
        ans++;
        return;
    }
    for(int num=1;num<=n;num++){
        if(!used[num] && (pos%num==0 || num%pos==0)){
            used[num]=true;
            solve(pos+1,used,n,ans);
            used[num]=false;
        }
    }
}
    int countArrangement(int n) {
        vector<int>used(n+1,false);
        int ans=0;
        solve(1,used,n,ans);
        return ans;
    }
};