class Solution {
public:
const int M=1e9+7;
typedef long long ll;
    int distinctSubseqII(string s) {
        int n=s.size();
        vector<ll>t(n+1,0);
        vector<int>last_seen(256,-1);
        t[0]=1; // empty subsequence
        for(int i=1;i<=n;i++){
            t[i]=(2*t[i-1])%M;
            char c=s[i-1];
            if(last_seen[c]!=-1){
                int j=last_seen[c];
                t[i]=(t[i]-t[j-1]+M)%M;
            }
            last_seen[c]=i;
        }
        return (t[n]-1+M)%M;
    }
};