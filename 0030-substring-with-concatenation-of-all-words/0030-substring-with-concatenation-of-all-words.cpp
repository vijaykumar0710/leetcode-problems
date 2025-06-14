class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;

        int word_len = words[0].size();
        int word_count = words.size();
        int total_len = word_len * word_count;
        int n = s.size();

        unordered_map<string, int> word_map;
        for (const string& word : words)
            word_map[word]++;

        // Try all possible starting offsets (0 to word_len - 1)
        for (int offset = 0; offset < word_len; ++offset) {
            unordered_map<string, int> window_map;
            int left = offset, right = offset, matched = 0;

            while (right + word_len <= n) {
                string word = s.substr(right, word_len);
                right += word_len;

                // Word is part of target
                if (word_map.count(word)) {
                    window_map[word]++;
                    matched++;

                    // If word occurs too many times, shrink window
                    while (window_map[word] > word_map[word]) {
                        string left_word = s.substr(left, word_len);
                        window_map[left_word]--;
                        left += word_len;
                        matched--;
                    }

                    // If full match
                    if (matched == word_count)
                        res.push_back(left);
                }
                // Word not in list → reset window
                else {
                    window_map.clear();
                    matched = 0;
                    left = right;
                }
            }
        }

        return res;
    }
};
