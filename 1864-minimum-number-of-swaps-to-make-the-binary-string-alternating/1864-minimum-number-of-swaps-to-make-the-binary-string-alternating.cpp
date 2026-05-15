class Solution {
public:
    int odd(string& s,int ones,int zeros) {
        int n=s.size();
        char ch;
        if (ones > zeros)
            ch = '1';
        else
            ch = '0';
        int op1 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != ch)
                op1++;
            if (ch == '1')
                ch = '0';
            else
                ch = '1';
        }
        return op1;
    }
    int even(string& s) {
        int n=s.size();
        int op1 = 0;
        char ch = '1';
        int cnt_zeor = 0, cnt_ones = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] != ch)
                op1++;
            if (ch == '1')
                ch = '0';
            else
                ch = '1';
        }
        int op2 = 0;
        ch = '0';
        for (int i = 0; i < n; i++) {
            if (s[i] != ch)
                op2++;
            if (ch == '1')
                ch = '0';
            else
                ch = '1';
        }
        return min(op1, op2);
    }
    int minSwaps(string s) {
        int n = s.size();
        int ones = count(s.begin(), s.end(), '1');
        int zeros = count(s.begin(), s.end(), '0');
        if (n % 2 == 0) {
            if (ones != zeros)
                return -1;
        } else {
            if (abs(ones - zeros) > 1)
                return -1;
        }
        int res = INT_MAX;
        if (n % 2 == 1)
            res = min(res, odd(s,ones,zeros));
        else
            res = min(res, even(s));
        return res / 2;
    }
};