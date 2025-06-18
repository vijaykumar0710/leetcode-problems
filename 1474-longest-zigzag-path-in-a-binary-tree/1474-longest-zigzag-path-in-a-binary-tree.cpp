class Solution {
public:
int res;
void dfs(TreeNode* root,int parity,int len){
    if(!root) return;

    if(parity==1){
        dfs(root->right,-1,len+1);
        dfs(root->left,1,1);
    }else{
        dfs(root->left,1,len+1);
        dfs(root->right,-1,1);
    }
    res=max(res,len);
}
    int longestZigZag(TreeNode* root) {
        dfs(root,1,0);
        dfs(root,-1,0);
        return res;
    }
};