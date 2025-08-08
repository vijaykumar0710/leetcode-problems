class Solution {
public:
int cnt=0;
void dfs(TreeNode* node,int mask){
    if(!node) return;

    mask=mask^(1<<node->val);

    if(!node->left && !node->right){ 
    if(mask==0) cnt++;
    for(int i=0;i<10;i++){
        int new_mask=mask^(1<<i);
        if(new_mask==0) cnt++;
      }
    }

    dfs(node->left,mask);
    dfs(node->right,mask);
}
    int pseudoPalindromicPaths (TreeNode* root) {
        int mask=0;
        dfs(root,mask);
        return cnt;
    }
};