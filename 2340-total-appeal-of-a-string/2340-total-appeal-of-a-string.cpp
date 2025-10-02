typedef long long ll;
class Solution {
public:
    long long appealSum(string s) {
        int n=(int)s.size();
        ll total_substring=1LL*n*(n+1)/2;
        ll total_appeal=0;
        for(char ch='a';ch<='z';ch++){
            ll cnt=0,temp=0;
            for(int i=0;i<n;i++){
                if(s[i]!=ch) cnt++;
                else{ temp=(ll)temp+1LL*cnt*(cnt+1)/2; cnt=0; }
            }
            temp=(ll)temp+1LL*cnt*(cnt+1)/2;
            total_appeal=(ll)total_appeal+total_substring-temp;
        }
        return total_appeal;
    }
};