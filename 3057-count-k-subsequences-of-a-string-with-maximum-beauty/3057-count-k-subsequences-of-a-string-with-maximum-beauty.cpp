const int M = 1e9+7;
class Solution {
public:
    typedef long long ll;
    int N = 1e6;
    vector<ll> fact;

    ll mod_power(ll b,ll e){
        ll res = 1;
        while(e){
            if(e & 1) res = (res * b) % M;
            b = (b * b) % M;
            e >>= 1;
        }
        return res;
    }

    ll nCr(int n,int r){
        if(r<0 || r>n) return 0;
        ll a = fact[n];
        ll b = (fact[r] * fact[n-r]) % M;
        return (a * mod_power(b, M-2)) % M;
    }

    int countKSubsequencesWithMaxBeauty(string s, int k) {
        fact.resize(N+1);
        fact[0] = 1;
        for(int i=1;i<=N;i++){
            fact[i] = (fact[i-1] * i) % M;
        }

        vector<int> fre(26,0);
        for(auto &ch:s) fre[ch-'a']++;
        sort(fre.rbegin(),fre.rend());

        int cnt = 0;
        for(int f:fre) if(f>0) cnt++;
        if(cnt < k) return 0;

        int tie_fre = fre[k-1];
        int total_tie_fre = count(fre.begin(), fre.end(), tie_fre);

        ll res = 1;
        int need = k;
        for(int f:fre){
            if(f > tie_fre){
                res = (res * f) % M;
                need--;
            }
        }

        // If no tie frequency needed
        if(need == 0) return res % M;

        // Choose needed from tie frequencies
        ll remain = nCr(total_tie_fre, need);
        res = (res * remain) % M;
        res = (res * mod_power(tie_fre, need)) % M;

        return res % M;
    }
};
