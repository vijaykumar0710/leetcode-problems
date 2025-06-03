#include <string>
#include <vector>
#include <algorithm> // For std::reverse, std::min

// Computes the Z-array for a given string.
// z[i] is the length of the longest common prefix between str and str.substr(i).
// z[0] is typically set to the length of str or 0; here, we set it to str.length().
std::vector<int> compute_z_array(const std::string& str) {
    int n_str = str.length();
    if (n_str == 0) {
        return {};
    }
    std::vector<int> z(n_str);
    
    int l = 0, r = 0;
    for (int i = 1; i < n_str; ++i) {
        if (i <= r) {
            z[i] = std::min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n_str && str[z[i]] == str[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    z[0] = n_str; // Set z[0] to the length of the string
    return z;
}

class Solution {
public:
    int minStartingIndex(std::string s, std::string pattern) {
        int n_s = s.length();
        int m_pattern = pattern.length();

        if (m_pattern == 0) { // Constraint: 1 <= pattern.length, but good practice
            return 0; 
        }
        if (m_pattern > n_s) {
            return -1;
        }

        // 1. Compute LCPs: LCP(pattern, s.substr(i))
        // lcp_s_pattern[i] stores this value, capped at m_pattern.
        std::string s_forward_concat = pattern + '$' + s;
        std::vector<int> z_forward = compute_z_array(s_forward_concat);
        std::vector<int> lcp_s_pattern(n_s); 
        for (int i = 0; i < n_s; ++i) {
            // Index in z_forward for s.substr(i) is (m_pattern (for pattern) + 1 (for '$') + i)
            if (m_pattern + 1 + i < z_forward.size()) {
                lcp_s_pattern[i] = std::min(m_pattern, z_forward[m_pattern + 1 + i]);
            } else {
                lcp_s_pattern[i] = 0; 
            }
        }
        
        // 2. Compute LCSs: LCS(pattern, s.substr(i, m_pattern))
        // This is equivalent to LCP(reverse(pattern), reverse(s.substr(i, m_pattern)))
        // lcs_window[i] stores this value for window s.substr(i, m_pattern)
        std::string pattern_rev = pattern;
        std::reverse(pattern_rev.begin(), pattern_rev.end());
        std::string s_rev = s;
        std::reverse(s_rev.begin(), s_rev.end());

        std::string s_backward_concat = pattern_rev + '$' + s_rev;
        std::vector<int> z_backward = compute_z_array(s_backward_concat);
        
        // lcs_window stores LCS for each possible window of length m_pattern in s
        std::vector<int> lcs_window(n_s - m_pattern + 1); 

        for (int i = 0; i <= n_s - m_pattern; ++i) { // i is the start of the window in original s
            // The reversed window s[i...i+m_pattern-1]_rev
            // starts in s_rev at index: n_s - (i + m_pattern - 1) - 1 = n_s - i - m_pattern
            int start_idx_in_s_rev = n_s - i - m_pattern;
            
            if (m_pattern + 1 + start_idx_in_s_rev < z_backward.size()) {
                lcs_window[i] = std::min(m_pattern, z_backward[m_pattern + 1 + start_idx_in_s_rev]);
            } else {
                 lcs_window[i] = 0;
            }
        }

        // 3. Iterate through windows in s to find the smallest starting index
        for (int i = 0; i <= n_s - m_pattern; ++i) { 
            // current_lcp is LCP of pattern and s.substr(i), effectively for the window s.substr(i, m_pattern)
            int current_lcp = lcp_s_pattern[i]; 
            // current_lcs is LCS of pattern and the window s.substr(i, m_pattern)
            int current_lcs = lcs_window[i];    

            // Case 0: Exact match
            // If LCP of pattern and s.substr(i) covers the full pattern length
            if (current_lcp == m_pattern) { 
                return i;
            }

            // Case 1: One mismatch
            // This occurs if the sum of LCP (from left) and LCS (from right) 
            // leaves exactly one character of the pattern unmatched.
            // So, current_lcp + current_lcs == m_pattern - 1.
            if (current_lcp + current_lcs == m_pattern - 1) {
                // The potential mismatch is at pattern[current_lcp] 
                // and its corresponding character in s is s[i + current_lcp].
                // This condition (current_lcp + current_lcs == m_pattern - 1) implies current_lcp < m_pattern.
                // The character s[i + current_lcp] is within the window s[i...i+m_pattern-1].
                if (s[i + current_lcp] != pattern[current_lcp]) {
                    return i;
                }
            }
        }
        return -1; // No such substring found
    }
};
