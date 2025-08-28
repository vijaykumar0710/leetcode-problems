typedef long long ll;
const int M=1e9+7;
class Solution {
public:
int t[100001];
int f(int st,string &s,int k,int n){
    if(st>=n) return 1;
    if(s[st]=='0') return 0;
    if(t[st]!=-1) return t[st];
    ll res=0;
    ll num=0;
    for(int end=st;end<n;end++){
        num=(ll)(num*10)+(s[end]-'0');
        if(num>k) break;
        if(num<=k && num>=1){
            res+=f(end+1,s,k,n);
        }
    }
    return t[st]=res%M;
}
    int numberOfArrays(string s, int k) {
        int n=s.size();
        memset(t,-1,sizeof(t));
        return f(0,s,k,n);
    }
};