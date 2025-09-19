class Solution {
public:
    struct trieNode {
        trieNode* children[26];
        pair<int,int> pairs; // {length, index}
        trieNode() {
            pairs = {100000, 100000};
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };

    trieNode* root;

    Solution() {
        root = new trieNode();
    }

    ~Solution() {  // destructor to free memory
        freeTrie(root);
    }

    void freeTrie(trieNode* node) {
        if (!node) return;
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                freeTrie(node->children[i]);
            }
        }
        delete node;
    }

    void insert(string &word, int j, trieNode *root) {
        trieNode *crawler = root;
        for (int i = word.size() - 1; i >= 0; i--) {
            int idx = word[i] - 'a';
            if (!crawler->children[idx]) crawler->children[idx] = new trieNode();
            crawler = crawler->children[idx];
            if ((int)word.size() < crawler->pairs.first) {
                crawler->pairs.first = word.size();
                crawler->pairs.second = j;
            }
        }
    }

    void prefix_search(string &word, trieNode* root, vector<int>& res) {
        trieNode *crawler = root;
        int i = word.size() - 1;
        for (; i >= 0; i--) {
            int idx = word[i] - 'a';
            if (!crawler->children[idx]) {
                res.push_back(crawler->pairs.second);
                return;
            }
            crawler = crawler->children[idx];
        }
        if (i < 0) res.push_back(crawler->pairs.second);
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int m = wordsContainer.size();
        int n = wordsQuery.size();

        int smaller = 1e6, small_idx = n;
        for (int i = 0; i < m; i++) {
            if ((int)wordsContainer[i].size() < smaller) {
                smaller = (int)wordsContainer[i].size();
                small_idx = i;
            }
            insert(wordsContainer[i], i, root);
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            prefix_search(wordsQuery[i], root, res);
        }
        for (auto &x : res) if (x == 100000) x = small_idx;
        return res;
    }
};