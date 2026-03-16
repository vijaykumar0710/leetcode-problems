class Solution {
public:
    int t[100005];
    int f(int n) {
        if (n == 0) return 0;
        if ((n & (n - 1)) == 0) return 1;
        if(t[n]!=-1) return t[n];
        if (n % 2 == 0) return t[n] = f(n / 2);
        else {
            int add = 1 + f((n + 1) / 2);
            int sub = 1 + f((n - 1) / 2);
            return t[n] = min(add, sub);
        }
    }
    int minOperations(int n) { 
        memset(t,-1,sizeof(t));
        return f(n);
      }
};