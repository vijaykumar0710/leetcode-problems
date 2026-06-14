class Codec {
public:
    void preorder(TreeNode* root, string& s) {
        if(root == NULL) return;
        s += to_string(root->val) + ",";
        preorder(root->left, s);
        preorder(root->right, s);
    }
    string serialize(TreeNode* root) {
        string s = "";
        preorder(root, s);
        return s;
    }
    TreeNode* build(vector<int>& v, int& idx, int bound) {
        if(idx == v.size() || v[idx] > bound) {
            return NULL;
        }
        TreeNode* root = new TreeNode(v[idx]);
        idx++;
        root->left = build(v, idx, v[idx-1]);
        root->right = build(v, idx, bound);
        return root;
    }
    TreeNode* deserialize(string data) {
        vector<int> v;
        string temp = "";
        for(char ch : data) {
            if(ch == ',') {
                v.push_back(stoi(temp));
                temp = "";
            } else {
                temp += ch;
            }
        }
        int idx = 0;
        return build(v, idx, INT_MAX);
    }
};