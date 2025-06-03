#include <string>
#include <vector>
#include <algorithm>

std::vector<int> compute_z_array(const std::string& str) {
    int n_str = str.length();
    if (n_str == 0) {
        return {};
    }

    std::vector<int> z_array(n_str);
    z_array[0] = n_str; 

    int left_boundary = 0; 
    int right_boundary = 0; 

    for (int i = 1; i < n_str; ++i) {
        if (i <= right_boundary) {
            int k_in_prefix = i - left_boundary;
            z_array[i] = std::min(right_boundary - i + 1, z_array[k_in_prefix]);
        }
        
        while (i + z_array[i] < n_str && str[z_array[i]] == str[i + z_array[i]]) {
            z_array[i]++;
        }
        
        if (i + z_array[i] - 1 > right_boundary) {
            left_boundary = i;
            right_boundary = i + z_array[i] - 1;
        }
    }
    return z_array;
}

class Solution {
public:
    int minStartingIndex(std::string s, std::string pattern) {
        int n_s = s.length();
        int m_pattern = pattern.length();

        if (m_pattern == 0) {
            return 0; 
        }
        if (m_pattern > n_s) {
            return -1;
        }

        std::string forward_concatenated_string = pattern + '$' + s;
        std::vector<int> z_values_forward = compute_z_array(forward_concatenated_string);
        
        std::vector<int> lcp_s_pattern(n_s); 
        for (int i = 0; i < n_s; ++i) {
            if (m_pattern + 1 + i < z_values_forward.size()) {
                lcp_s_pattern[i] = std::min(m_pattern, z_values_forward[m_pattern + 1 + i]);
            } else {
                lcp_s_pattern[i] = 0; 
            }
        }
        
        std::string reversed_pattern = pattern;
        std::reverse(reversed_pattern.begin(), reversed_pattern.end());
        
        std::string reversed_s = s;
        std::reverse(reversed_s.begin(), reversed_s.end());

        std::string backward_concatenated_string = reversed_pattern + '$' + reversed_s;
        std::vector<int> z_values_backward = compute_z_array(backward_concatenated_string);
        
        std::vector<int> lcs_window(n_s - m_pattern + 1); 
        for (int i = 0; i <= n_s - m_pattern; ++i) { 
            int start_idx_in_reversed_s = n_s - i - m_pattern;
            
            if (m_pattern + 1 + start_idx_in_reversed_s < z_values_backward.size()) {
                lcs_window[i] = std::min(m_pattern, z_values_backward[m_pattern + 1 + start_idx_in_reversed_s]);
            } else {
                lcs_window[i] = 0; 
            }
        }

        for (int i = 0; i <= n_s - m_pattern; ++i) { 
            int current_lcp = lcp_s_pattern[i]; 
            int current_lcs = lcs_window[i]; 
            
            if (current_lcp == m_pattern) { 
                return i; 
            }

            if (current_lcp + current_lcs == m_pattern - 1) {
                if (s[i + current_lcp] != pattern[current_lcp]) {
                    return i; 
                }
            }
        }
        
        return -1; 
    }
};

