class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int res = 0, i = 0;
        unordered_map<char, int> mp;
        for (int j = 0; j < n; j++) {
            mp[s[j]]++;
            while (mp.size() >= 3) {
                res += (n - j);
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
        }
        return res;
    }
};