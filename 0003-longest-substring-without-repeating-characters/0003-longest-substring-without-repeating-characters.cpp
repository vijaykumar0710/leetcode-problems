class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); ++right) {
            freq[s[right]]++;

            // shrink until window becomes valid (no char has freq > 1)
            while (freq[s[right]] > 1) {
                freq[s[left]]--;
                if(freq[s[left]]==0) freq.erase(s[left]);
                ++left;
            }

            // window [left, right] is valid
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
