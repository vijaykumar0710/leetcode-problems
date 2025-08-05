class Solution {
public:
const int M=1e9+7;
unordered_map<TreeNode*,long long>subtree_sum;
long long res=0;
long long total=0;
void dfs1(TreeNode *node){
    if(!node) return;
    subtree_sum[node]=node->val;
    for(auto &child:{node->left,node->right}){
        dfs1(child);
        subtree_sum[node]+=subtree_sum[child];
        total=max(total,subtree_sum[node]);
    }
}
void dfs2(TreeNode* node){
    if(!node) return;
for(auto &child:{node->left,node->right}){
   res=max(res,1ll*subtree_sum[child]*(total-subtree_sum[child]));
}
for(auto &child:{node->left,node->right}){
    int subtree_sum_node=subtree_sum[node];
    int subtree_sum_child=subtree_sum[child];

    subtree_sum[node]-=subtree_sum[child];
    subtree_sum[child]+=subtree_sum[node];

    dfs2(child);

     subtree_sum[node]=subtree_sum_node;
     subtree_sum[child]=subtree_sum_child;
   }
}
    int maxProduct(TreeNode* root) {
        dfs1(root);
        dfs2(root);
        return res%M;
    }
};