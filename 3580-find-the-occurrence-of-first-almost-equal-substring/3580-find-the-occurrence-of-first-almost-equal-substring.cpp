#include <string>
#include <vector>
#include <algorithm>

std::vector<int> compute_z_array(const std::string& str) {
    int n = str.length();
    std::vector<int> z(n);
    int l = 0, r = 0;

    for (int i = 1; i < n; ++i) {
        if (i <= r)
            z[i] = std::min(r - i + 1, z[i - l]);

        while (i + z[i] < n && str[z[i]] == str[i + z[i]])
            ++z[i];

        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }

    z[0] = n;
    return z;
}

class Solution {
public:
    int minStartingIndex(std::string s, std::string pattern) {
        int n = s.length(), m = pattern.length();
        if (m == 0) return 0;
        if (m > n) return -1;

        // LCP (prefix match)
        std::string concat_fwd = pattern + '$' + s;
        auto z_fwd = compute_z_array(concat_fwd);
        std::vector<int> lcp(n);
        for (int i = 0; i < n; ++i)
            lcp[i] = (m + 1 + i < z_fwd.size()) ? std::min(m, z_fwd[m + 1 + i]) : 0;

        // LCS (suffix match, reversed)
        std::reverse(s.begin(), s.end());
        std::reverse(pattern.begin(), pattern.end());
        std::string concat_bwd = pattern + '$' + s;
        auto z_bwd = compute_z_array(concat_bwd);

        std::vector<int> lcs(n - m + 1);
        for (int i = 0; i <= n - m; ++i) {
            int rev_idx = n - i - m;
            lcs[i] = (m + 1 + rev_idx < z_bwd.size()) ? std::min(m, z_bwd[m + 1 + rev_idx]) : 0;
        }

        std::reverse(s.begin(), s.end());  // restore s
        std::reverse(pattern.begin(), pattern.end());  // restore pattern

        for (int i = 0; i <= n - m; ++i) {
            if (lcp[i] == m) return i;  // exact match

            if (lcp[i] + lcs[i] == m - 1) {
                if (s[i + lcp[i]] != pattern[lcp[i]])
                    return i;  // one mismatch
            }
        }

        return -1;  // no match found
    }
};
