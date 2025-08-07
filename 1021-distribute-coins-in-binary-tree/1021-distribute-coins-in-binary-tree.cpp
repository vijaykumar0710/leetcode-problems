class Solution {
public:
int moves=0;
int dfs(TreeNode* node){
    if(!node) return 0;
    int left=dfs(node->left);
    int right=dfs(node->right);
    moves+=(abs(left)+abs(right));
    return node->val+left+right-1;
}
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return moves;
    }
};