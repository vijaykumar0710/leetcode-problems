class Solution {
public:
    long long f(string& s, string pattern, long long schar) {
        int m = s.size();
        long long cnt = 0;
        long long pcnt = 0;
        for (int i = 0; i <= m; i++) {
            if (s[i] == pattern[1])
                pcnt++;
            if (s[i] == pattern[0])
                cnt += (schar - pcnt);
        }
        return cnt;
    }
    long long maximumSubsequenceCount(string text, string pattern) {
        int m = text.size();
        long long res = INT_MIN;
        long long schar = 0;
        for (auto ch : text)
            if (ch == pattern[1])
                schar++;
        string s1 = pattern[0] + text;
        res = max(res, f(s1, pattern, schar));
        s1 = text + pattern[1];
        schar++;
        res = max(res, f(s1, pattern, schar));
        return res;
    }
};