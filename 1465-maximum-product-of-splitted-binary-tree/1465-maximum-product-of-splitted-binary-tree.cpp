class Solution {
public:
const int M=1e9+7;
unordered_map<TreeNode*,long long> subtree_sum;
long long product=1;
long long total=0;
 void dfs1(TreeNode* node, TreeNode* parent) {
    if (!node) return;

    subtree_sum[node] = node->val;

    for (TreeNode* child : {node->left, node->right}) {
        if (!child) continue;

        dfs1(child, node);

        subtree_sum[node] += subtree_sum[child];
        total=max(total,subtree_sum[node]);
    }
}
 
 void dfs2(TreeNode* node, TreeNode* parent) {
    for(TreeNode* child:{node->left, node->right}){
        if(!child) continue;
    long long left_sum=subtree_sum[node->left];
    long long right_sum=subtree_sum[node->right];
    long long product_left_sum=left_sum*(total-left_sum);
    long long product_right_sum=right_sum*(total-right_sum);
    product=max({product,product_left_sum,product_right_sum});
    }
        for (TreeNode* child : {node->left, node->right}) {
            if (!child) continue;

            // Backup
            int sz_node = subtree_sum[node], sz_child = subtree_sum[child];

            // Remove child contribution from parent
            subtree_sum[node] -= subtree_sum[child];

            // Add parent contribution to child
            subtree_sum[child] += subtree_sum[node];

            dfs2(child, node);

            // Restore
            subtree_sum[node] = sz_node;
            subtree_sum[child] = sz_child;
        }
    }
    int maxProduct(TreeNode* root) {
        dfs1(root,NULL);
        dfs2(root,NULL);
        return product%M;
    } 
};