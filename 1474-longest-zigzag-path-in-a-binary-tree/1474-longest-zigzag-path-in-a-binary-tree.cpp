class Solution {
public:
int res=0;
int dfs(TreeNode *node,int dir,int cnt){
    if(!node) return 0;
    if(dir==0){
         dfs(node->left,1,cnt+1);
         dfs(node->right,0,cnt);
    }else{
         dfs(node->right,0,cnt+1);
         dfs(node->left,1,cnt);
    }
   return res=max(res,cnt);
}
    int longestZigZag(TreeNode* root) {
         dfs(root,0,0);
         dfs(root,1,0);
         return res;
    }
};