class Solution {
public:
TreeNode* prev=NULL;
bool inorder(TreeNode* root){
    if(!root) return true;
    bool flag=true;
    flag&=inorder(root->left);
    if(prev && prev->val>=root->val) return false;
    prev=root;
    flag&=inorder(root->right);
    return flag;
}
    bool isValidBST(TreeNode* root) {
       return inorder(root);
    }
};