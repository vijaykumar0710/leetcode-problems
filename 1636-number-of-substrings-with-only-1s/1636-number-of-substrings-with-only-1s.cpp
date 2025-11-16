const int M=1e9+7;
class Solution {
public:
    int numSub(string s) {
        int n=s.size();
        long long res=0;
        int cnt=0;
        for(int i=0;i<n;i++){
          if(s[i]=='1') cnt++;
          else{
            res=(res+((1ll*cnt*(cnt+1))/2))%M;
            cnt=0;
          }
        }
        res=(res+((1ll*cnt*(cnt+1))/2))%M;
        return res;
    }
};