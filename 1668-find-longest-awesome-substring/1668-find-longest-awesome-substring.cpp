class Solution {
public:
    int longestAwesome(string s) {
        int n = s.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq(10, 0); 
            for (int j = i; j < n; j++) {
                freq[s[j] - '0']++;
                int oddCount = 0;
                for (int d = 0; d < 10; d++) {
                    if (freq[d] % 2 != 0) oddCount++;
                }
                if (oddCount <= 1) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};