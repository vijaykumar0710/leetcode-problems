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
vector<int>inor;
void inorder(TreeNode* root){
    if(!root) return;
    inorder(root->left);
    inor.push_back(root->val);
    inorder(root->right);
}
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        inor.clear();
        inorder(root);
        for(int i=0;i<inor.size()-1;i++){
            if(inor[i]>=inor[i+1]) return false;
        }
        return true;
    }
};