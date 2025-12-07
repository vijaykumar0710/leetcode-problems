class Solution {
public:
vector<int>inor;
void inorder(TreeNode* root){
    if(!root) return;
    inorder(root->left);
    inor.push_back(root->val);
    inorder(root->right);
}
    bool isValidBST(TreeNode* root) {
        inor.clear();
        inorder(root);
        for(int i=0;i<inor.size()-1;i++){
            if(inor[i]>=inor[i+1]) return false;
        }
        return true;
    }
};