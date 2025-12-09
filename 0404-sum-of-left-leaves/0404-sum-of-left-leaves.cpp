/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int sum=0;
void f(TreeNode* root){ 
    if(!root) return; 
    f(root->left);
    f(root->right);
     if(root->left) sum+=root->left->val;
}
    int sumOfLeftLeaves(TreeNode* root) {
        f(root);
        return sum;
    }
};