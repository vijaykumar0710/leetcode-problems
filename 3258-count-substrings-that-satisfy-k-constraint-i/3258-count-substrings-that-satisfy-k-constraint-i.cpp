class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n=s.size();
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int ones=0,zeros=0;
                for(int it=i;it<=j;it++){
                  if(s[it]=='0') zeros++;
                  else ones++;
                }
                if(ones<=k || zeros<=k) res++;
            }
        }
        return res;
    }
};