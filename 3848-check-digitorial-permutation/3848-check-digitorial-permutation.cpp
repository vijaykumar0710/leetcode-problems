class Solution {
public:
    bool isDigitorialPermutation(int n) {
        int N=n;
        int sum=0;
        while(n){
            int digit=n%10;
            n/=10;
            int fact=1;
            for(int i=2;i<=digit;i++) fact*=i;
            sum+=fact;
        }
        string s1=to_string(N);
        string s2=to_string(sum);
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        return s1==s2;
    }
};