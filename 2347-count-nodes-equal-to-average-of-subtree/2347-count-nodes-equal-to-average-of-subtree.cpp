class Solution {
public:
int res=0;
pair<int,int>dfs(TreeNode *node){
    if(!node) return {0,0};

    auto left=dfs(node->left);
    auto right=dfs(node->right);

    int left_cnt=left.first;
    int right_cnt=right.first;

    int left_sum=left.second;
    int right_sum=right.second;

    int total=left_cnt+right_cnt+1;
    int total_sum=node->val+left_sum+right_sum;

    if(total_sum/total==node->val){
        res++;
        return {total,total_sum};
    }else{
        return {total,total_sum};
    }
}
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return res;
    }
};