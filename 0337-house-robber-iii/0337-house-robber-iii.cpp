class Solution {
public:
  unordered_map<TreeNode* ,vector<int>>dp;
  vector<int>dfs(TreeNode* root){
    if(!root) return {0,0};

    auto left=dfs(root->left);
    auto right=dfs(root->right);

    int exclude=max(left[0],left[1])+max(right[0],right[1]);
    int include=root->val+left[0]+right[0];

    return {exclude,include};
  }
    int rob(TreeNode* root) {
      auto res=dfs(root);
      return max(res[0],res[1]);
    }
};