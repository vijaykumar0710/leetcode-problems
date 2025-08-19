class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n=s.size();
        int res=1;
        int i=1;
        while(i<n){
            int cnt=1;
            while((s[i]-s[i-1])==1){
                cnt++;
                i++;
            }
            res=max(res,cnt);
            i++;
        }
        return res;
    }
};