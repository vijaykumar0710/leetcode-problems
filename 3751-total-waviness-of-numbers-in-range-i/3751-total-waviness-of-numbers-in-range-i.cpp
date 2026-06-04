class Solution {
public:
    int f(string &s){
        int n=s.size();
        int res=0;
            for(int i=1;i<n-1;i++){
                if((s[i]>s[i-1] && s[i]>s[i+1]) || (s[i]<s[i-1] && s[i]<s[i+1])) res++;
            }
        return res;
    }
    int totalWaviness(int num1, int num2) {
        if(num1<100 && num2<100) return 0;
        long long res=0;
        for(int i=num1;i<=num2;i++){
            string s=to_string(i);
            res=(long long)res+f(s);
        }
        return res;
    }
};