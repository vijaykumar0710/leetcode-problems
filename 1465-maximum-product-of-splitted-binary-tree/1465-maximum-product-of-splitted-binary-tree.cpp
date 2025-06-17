class Solution {
public:
const int M=1e9+7;
unordered_map<TreeNode*,long long> subtree_sum;
long long product=1;
long long total=0;
 void dfs1(TreeNode* node) {
    if (!node) return;

    dfs1(node->left);
    dfs1(node->right);

    int leftSum = node->left ? subtree_sum[node->left] : 0;
    int rightSum = node->right ? subtree_sum[node->right] : 0;

    subtree_sum[node] = node->val + leftSum + rightSum;
        total=max(total,subtree_sum[node]);
    }
 
 void dfs2(TreeNode* node, TreeNode* parent) {
    for (TreeNode* child : {node->left, node->right}) {
    if (!child) continue;
    long long part1=subtree_sum[child];
    long long part2=(total-part1);
    product=max(product,part1*part2);

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
        dfs1(root);
        dfs2(root,NULL);
        return product%M;
    } 
};