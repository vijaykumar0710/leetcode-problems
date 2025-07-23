class Solution {
public:
    int t[31];
    int f(int n) {
        int res = 0;
        if (t[n] != -1)
            return t[n];
        if (n == 0 || n == 1)
            return n;
            res = fib(n - 1) + fib(n - 2);
        return t[n] = res;
    }
    int fib(int n) {
        memset(t, -1, sizeof(t));
        return f(n);
    }
};