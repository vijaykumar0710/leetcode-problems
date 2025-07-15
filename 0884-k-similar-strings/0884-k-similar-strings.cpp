class Solution {
public:
    int kSimilarity(string s1, string s2) {
        int n = s1.size();
        int k = 0;
        unordered_set<string> st;
        queue<pair<string, int>> q;

        q.push({s1, 0});
        st.insert(s1);

        while (!q.empty()) {
            auto [s, k] = q.front();
            q.pop();
            if (s2 == s)
                return k;
            int i = 0;

            while (i < s.size() && s[i] == s2[i])
                i++;
            for (int j = i + 1; j < n; j++) {
                if (s[j] == s2[i] && s[j] != s2[j]) {
                swap(s[i], s[j]);
                if (st.count(s) == 0) {
                    st.insert(s);
                    q.push({s, k + 1});
                }
                swap(s[i], s[j]);
            }
            }
        }
        return k;
    }
};
