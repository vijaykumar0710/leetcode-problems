class Solution {
public:
const long long b = 31;
    unordered_map<unsigned long long, int> m;
    void update(unsigned long long hash, int idx, vector<string>& wordsContainer) {
        if (m.find(hash) == m.end()) {
            m[hash] = idx;
        } else { 
            int curr = m[hash];
            if (wordsContainer[idx].length() < wordsContainer[curr].length()) {
                m[hash] = idx;
            }
        }
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        for (int k = 0; k < wordsContainer.size(); k++) {
            unsigned long long  hash=0;
            update(0, k, wordsContainer); 
            for (int i = wordsContainer[k].size() - 1; i >= 0; i--) {
                 hash=(hash*b+wordsContainer[k][i]);
                update(hash, k, wordsContainer);
            }
        }
        vector<int> res(wordsQuery.size(), 0);
            for (int i = 0; i < wordsQuery.size(); i++) {
            res[i] = m[0]; 
            unsigned long long hash=0;
            for (int j = wordsQuery[i].size() - 1; j >= 0; j--) {
                 hash=(hash*b+wordsQuery[i][j]);
                if (m.count(hash)) {
                    res[i] = m[hash]; 
                } else {
                    break; 
                }
            }
        }
        return res;
    }
};