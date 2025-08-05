class Solution {
public:
pair<int,int> dfs(TreeNode* node){
    if(!node) return {0,0};
    auto left=dfs(node->left);
    auto right=dfs(node->right);

    auto include=node->val+left.first+right.first;
    auto exclude=max(left.first,left.second)+max(right.first,right.second);

   return {exclude,include};
}
    int rob(TreeNode* root) {
        auto ans=dfs(root);
       return max(ans.first,ans.second);
    }
};