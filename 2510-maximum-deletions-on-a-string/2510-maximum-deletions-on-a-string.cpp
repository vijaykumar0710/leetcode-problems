class Solution {
public:
int t[4001][4001];
int f(int l,int r,string &s,int n){
    if(l==n && r==n) return 0;
    if(r==n) return -1e9;
    if(r-l+1>n-r+1) return -1e9;
    if(t[l][r]!=-1) return t[l][r];
    int res=0;
    int len=r-l+1;
    if(s.compare(l,len,s,r+1,len)==0){
        res=max(res,1+f(r+1,r+1,s,n));
    }
    res=max(res,max(1+f(n,n,s,n),f(l,r+1,s,n)));
    return t[l][r]=res;
}
    int deleteString(string s) {
        int n=s.size();
        memset(t,-1,sizeof(t));
        return f(0,0,s,n);
    }
};