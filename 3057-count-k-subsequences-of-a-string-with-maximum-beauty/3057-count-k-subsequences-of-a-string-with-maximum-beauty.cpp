const int M=1e9+7;
class Solution {
public:
typedef long long ll;
int N=2*1e5+1;
vector<ll>fact;

ll mod_power(ll b,ll e){
    ll pro=1;
    b%=M;
    while(e>0){
        if(e%2==1) pro=(pro*b)%M;
        b=(b*b)%M;
        e/=2;
    }
    return pro;
}

ll nCr(int n,int r){
    if(r<0 || r>n) return 0;
    ll a=fact[n];
    ll b=(fact[r]*fact[n-r])%M;
    return (a*mod_power(b,M-2))%M;
}

    int countKSubsequencesWithMaxBeauty(string s, int k) {
        fact.resize(N);
        fact[0]=1;
        for(int i=1;i<N;i++){
           fact[i]=(fact[i-1]*i)%M;
        }
        int n=s.size();
        vector<int>fre(26,0);

        for(auto &ch:s) fre[ch-'a']++;
        sort(fre.rbegin(),fre.rend());

        int cnt=0;
        for(int i=0;i<fre.size();i++){
            if(fre[i]>0) cnt++;
        }
        if(cnt<k) return 0;

        int need=k;
        int tie_fre=fre[k-1];
        ll res=1;
        for(int i=0;i<fre.size();i++){
            if(fre[i]>tie_fre){
                res=(res*fre[i])%M;
                need--;
            }
        } 
      if(need==0) return res%M;

      int total_tie_fre=count(fre.begin(),fre.end(),tie_fre);

      long long remain=nCr(total_tie_fre,need);
      res=(res%M*remain%M*mod_power(tie_fre,need)%M)%M;
     return (int)res;
    }
};