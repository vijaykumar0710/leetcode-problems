class Solution {
public:
pair<int,TreeNode*>dfs(TreeNode* node){
    if(!node) return {0,NULL};

    auto left=dfs(node->left);
    auto right=dfs(node->right);
    
    int left_depth=left.first;
    int right_depth=right.first;

    if(left_depth==right_depth){
        return {left_depth+1,node};
    }else if(left_depth>right_depth){
        return {left_depth+1,left.second};
    }else return {right_depth+1,right.second};
}
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};