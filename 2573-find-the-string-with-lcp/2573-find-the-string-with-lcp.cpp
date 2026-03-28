class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
    int n = lcp.size();
    if (n == 0) return "";    
    string s(n, ' '); 
    for (int i = 0; i < n; i++) {
        if (s[i] != ' ') continue; 
        char c = 'a';
        while (c <= 'z') {
            bool valid = true;
            for (int j = 0; j < i; j++) {
                if (lcp[i][j] == 0 && s[j] == c) {
                    valid = false;
                    break;
                }
            }
            if (valid) break;
            c++;
        }
        if (c > 'z') return ""; 
        s[i] = c;
    }
    vector<vector<int>> actual_lcp(n + 1, vector<int>(n + 1, 0));    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (s[i] == s[j]) actual_lcp[i][j] = actual_lcp[i + 1][j + 1] + 1;
            else  actual_lcp[i][j] = 0;
            if (actual_lcp[i][j] != lcp[i][j]) return ""; 
        }
    }
    return s;
    }
};