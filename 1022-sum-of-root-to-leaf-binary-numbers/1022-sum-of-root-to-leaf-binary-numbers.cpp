class Solution {
public:
int sum = 0;
    void f(TreeNode* root,string &binary_string) {
        binary_string += to_string(root->val);
        if (root->left)  f(root->left,binary_string);
        if (root->right) f(root->right,binary_string);
        if (!root->left && !root->right){
            sum += stoi(binary_string, nullptr, 2);
            //return;
        }
        binary_string.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0;
        string binary_string="";
        f(root,binary_string);
        return sum;
    }
};