class Solution {
public:
const int M=1e9+7;
    int numberOfWays(string corridor) {
        int n=corridor.size();
        vector<int>s_idx;
        for(int i=0;i<n;i++) if(corridor[i]=='S') s_idx.push_back(i);
        if(s_idx.size()==2) return 1;
        if(s_idx.size()%2!=0 || s_idx.size()==0) return 0;
        long long res=1;
        for(int i=1;i<=s_idx.size()-3;i+=2) res=res*abs(s_idx[i]-s_idx[i+1])%M;
        return res%M;
    }
};