class Solution {
public:
TreeNode* first,*mid,*last,*prev;
void inorder(TreeNode* root){
    if(!root) return;
    inorder(root->left);
    if(prev!=NULL && prev->val>root->val){
        if(first==NULL){
            first=prev;
            mid=root;
        }else last=root;
    }
    prev=root;
    inorder(root->right);
}
    void recoverTree(TreeNode* root) {
        first=mid=last=prev=NULL;
        inorder(root);
        if(first && last) swap(first->val,last->val);
        else if(first && mid) swap(first->val,mid->val);
    }
};