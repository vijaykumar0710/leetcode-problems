#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, digit;
    set<long long> st;
    vector<int> digits;
    vector<int> used;
    void backtrack(long long num, int depth) {
        if (depth == digit) {
            if (num > n && num <= (1LL << 31) - 1) st.insert(num);
            return;
        }
        for (int i = 0; i < digits.size(); i++) {
                if (used[i]) continue;
                if (depth == 0 && digits[i] == 0) continue;
                used[i] = 1;
                backtrack(num * 10 + digits[i], depth + 1);
                used[i] = 0;
          }
    }
    int nextGreaterElement(int x) {
        n = x;
        digit = (int)log10(n) + 1;
        int m = n;
        digits.clear();
        while (m > 0) { digits.push_back(m % 10); m /= 10;}
        reverse(digits.begin(), digits.end());
        used.assign(digits.size(), 0);
        st.clear();
        backtrack(0, 0);
        if (st.empty()) return -1;
        return (int)*st.begin();
    }
};