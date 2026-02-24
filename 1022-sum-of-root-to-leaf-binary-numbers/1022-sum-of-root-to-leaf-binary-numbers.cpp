class Solution {
public:
int sum = 0;
    void f(TreeNode* root,string binary_string) {
        binary_string += to_string(root->val);
        if (!root->left && !root->right){
            sum += stoi(binary_string, nullptr, 2);
            //return;
        }
        if (root->left)  f(root->left,binary_string);
        if (root->right) f(root->right,binary_string);
        
    }
    int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0;
        f(root,"");
        return sum;
    }
};