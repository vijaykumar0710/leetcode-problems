class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        unordered_map<uint64_t, int> m;
        long long mod1 = 1000000007, mod2 = 1000000009;
        long long b1 = 31, b2 = 37;
        auto update = [&](uint64_t h, int idx) {
            if (m.find(h) == m.end()) {
                m[h] = idx;
            } else {
                int curr = m[h];
                if (wordsContainer[idx].length() < wordsContainer[curr].length()) {
                    m[h] = idx;
                }
            }
        };
        for (int i = 0; i < wordsContainer.size(); ++i) {
            long long h1 = 0, h2 = 0;
            long long p1 = 1, p2 = 1;
            update(0, i);
            for (int j = wordsContainer[i].length() - 1; j >= 0; --j) {
                long long val = wordsContainer[i][j] - 'a' + 1;
                h1 = (h1 + val * p1) % mod1;
                h2 = (h2 + val * p2) % mod2;
                p1 = (p1 * b1) % mod1;
                p2 = (p2 * b2) % mod2;
                update((h1 << 32) | h2, i);
            }
        }

        vector<int> ans;
        ans.reserve(wordsQuery.size());
        for (const string& q : wordsQuery) {
            vector<uint64_t> hlist;
            hlist.reserve(q.length() + 1);
            hlist.push_back(0);
            long long h1 = 0, h2 = 0;
            long long p1 = 1, p2 = 1;
            for (int j = q.length() - 1; j >= 0; --j) {
                long long val = q[j] - 'a' + 1;
                h1 = (h1 + val * p1) % mod1;
                h2 = (h2 + val * p2) % mod2;
                p1 = (p1 * b1) % mod1;
                p2 = (p2 * b2) % mod2;
                hlist.push_back((h1 << 32) | h2);
            }
            
            for (int j = hlist.size() - 1; j >= 0; --j) {
                if (m.find(hlist[j]) != m.end()) {
                    ans.push_back(m[hlist[j]]);
                    break;
                }
            }
        }
        return ans;
    }
};