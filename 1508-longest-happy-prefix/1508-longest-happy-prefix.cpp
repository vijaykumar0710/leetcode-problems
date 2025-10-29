class Solution {
public:
long long typedef ll;
struct RollingHash{
ll base=131;
ll M=1e9+7;
vector<ll>prefix,power;
RollingHash(string &s){
    int n=s.size();
    prefix.assign(n+1,0);
    power.assign(n+1,1);
    for(int i=0;i<n;i++){
        prefix[i+1]=(prefix[i]*base+s[i])%M;
        power[i+1]=(power[i]*base)%M;
    }
}
ll get_hash(int l,int r){
    return (prefix[r+1]+M-(prefix[l]*power[r-l+1]%M))%M;
  }
};
    string longestPrefix(string s) {
    int n=s.size();
    RollingHash rh(s);
    int len=0;
    for(int i=0;i<n-1;i++){
        int x=rh.get_hash(0,i);
        int y=rh.get_hash(n-i-1,n-1);
        if(x==y)len=max(len,i+1);
    }
    return s.substr(0,len);
    }
};