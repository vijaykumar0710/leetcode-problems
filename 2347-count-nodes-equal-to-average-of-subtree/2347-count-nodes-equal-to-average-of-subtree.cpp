class Solution {
public:
tuple<int,int,int>dfs(TreeNode* root){
    if(!root) return {0,0,0};

    auto left=dfs(root->left);
    auto right=dfs(root->right);

    int left_sum=get<0>(left);
    int right_sum=get<0>(right);

    int left_child_cnt=get<1>(left);
    int right_child_cnt=get<1>(right);

    int cnt=get<2>(left)+get<2>(right);

    int subtree_sum=left_sum+right_sum+root->val;
    int total_nodes=left_child_cnt+right_child_cnt+1;
    
    int average=subtree_sum/total_nodes;
    if(average==root->val) return {subtree_sum,total_nodes,cnt+1};
      return {subtree_sum,total_nodes,cnt};

}
    int averageOfSubtree(TreeNode* root) {
        return get<2>(dfs(root));
    }
};