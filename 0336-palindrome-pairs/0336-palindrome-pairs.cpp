class Solution {
public:
    bool isPalindrome(string &s, int l, int r) {
        while (l <= r) {
            if (s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        unordered_map<string,int> mp;
        for (int i=0;i<n;i++) mp[words[i]] = i;

        vector<vector<int>> res;

        for (int i=0; i<n; i++) {
            string w = words[i];
            int m = w.size();

            for (int cut=0; cut<=m; cut++) {  
                string prefix = w.substr(0, cut);
                string suffix = w.substr(cut);
                if (isPalindrome(w, 0, cut-1)) {
                    string revSuf = suffix;
                    reverse(revSuf.begin(), revSuf.end());
                    auto it = mp.find(revSuf);
                    if (it != mp.end() && it->second != i) {
                        res.push_back({it->second, i});
                    }
                }
                if (cut < m && isPalindrome(w, cut, m-1)) {
                    string revPre = prefix;
                    reverse(revPre.begin(), revPre.end());
                    auto it = mp.find(revPre);
                    if (it != mp.end() && it->second != i) {
                        res.push_back({i, it->second});
                    }
                }
            }
        }
        return res;
    }
};