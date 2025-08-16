class Solution {
public:
    static const long long MOD = 1000000007;

    // 2x2 matrix (a b / c d)
    struct Mat {
        long long a,b,c,d;
    };

    // multiply two 2x2 matrices
    Mat mul(const Mat &x,const Mat &y){
        Mat r;
        r.a = (x.a*y.a + x.b*y.c)%MOD;
        r.b = (x.a*y.b + x.b*y.d)%MOD;
        r.c = (x.c*y.a + x.d*y.c)%MOD;
        r.d = (x.c*y.b + x.d*y.d)%MOD;
        return r;
    }

    // fast power for 2x2 matrix
    Mat mpow(Mat base, long long p){
        Mat res {1,0,0,1}; // identity
        while(p>0){
            if(p&1) res = mul(res,base);
            base = mul(base,base);
            p >>= 1;
        }
        return res;
    }

    // build LPS for KMP
    vector<int> lpsBuild(string &pat){
        int n = pat.size();
        vector<int> lps(n,0);
        for(int i=1, j=0;i<n;i++){
            while(j>0 && pat[i]!=pat[j]) j = lps[j-1];
            if(pat[i] == pat[j]) j++;
            lps[i] = j;
        }
        return lps;
    }

    int numberOfWays(string s, string t, long long k) {
        int n = (int)s.size();

        // find which rotations of s equal t using KMP on (s+s)
        vector<int> good(n, 0);
        string cat = s + s;
        auto lps = lpsBuild(t);
        int j = 0;
        for(int i=0;i<cat.size();i++){
            while(j>0 && cat[i]!=t[j]) j = lps[j-1];
            if(cat[i] == t[j]) j++;
            if(j == (int)t.size()){
                int pos = i - (int)t.size() + 1;
                if(pos < n) good[pos] = 1;
                j = lps[j-1];
            }
        }

        // Build 2x2 transition matrix
        // sameNext = (n-1)*diff
        // diffNext = same + (n-2)*diff
        Mat M;
        M.a = 0;
        M.b = (n - 1) % MOD;
        M.c = 1;
        M.d = ( (long long)n - 2 + MOD ) % MOD;

        // compute M^k
        Mat Mk = mpow(M, k);

        // initial state: same = 1, diff = 0
        long long sameK = (Mk.a * 1 + Mk.b * 0) % MOD;
        long long diffK = (Mk.c * 1 + Mk.d * 0) % MOD;

        long long ans = 0;
        for(int i=0;i<n;i++){
            if(good[i]){
                if(i == 0) ans = (ans + sameK) % MOD;
                else       ans = (ans + diffK) % MOD;
            }
        }

        return (int)ans;
    }
};