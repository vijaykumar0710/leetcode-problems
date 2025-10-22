class Solution {
public:
struct RollingHash{
    vector<long long>prefix,power;
    long long mod=1e9+7;
    long long base=131;

    RollingHash(string &s){
        int n=s.size();
        prefix.assign(n+1,0);
        power.assign(n+1,1);
        for(int i=0;i<n;i++){
          prefix[i+1]=(prefix[i]*base+s[i])%mod;
          power[i+1]=(power[i]*base)%mod;
        }
    }
    long long get_hash(int l,int r){
        return(prefix[r+1]+mod-(prefix[l]*power[r-l+1])%mod)%mod;
    }
};
int t[4001][4001];
int f(int l,int r,string &s,int n,RollingHash &rh){
    if(l==n && r==n) return 0;
    if(r==n) return -1e9;
    if(r-l+1>n-r+1) return -1e9;
    if(t[l][r]!=-1) return t[l][r];
    int res=0;
    int len = r - l + 1;
   if(r + len < n && rh.get_hash(l, l + len - 1) == rh.get_hash(r+1, r + len)) {
    res = max(res, 1 + f(r + 1, r + 1, s, n, rh));
    }
    res=max(res,max(1+f(n,n,s,n,rh),f(l,r+1,s,n,rh)));
    return t[l][r]=res;
}
    int deleteString(string s) {
        RollingHash rh(s);
        int n=s.size();
        memset(t,-1,sizeof(t));
        return f(0,0,s,n,rh);
    }
};