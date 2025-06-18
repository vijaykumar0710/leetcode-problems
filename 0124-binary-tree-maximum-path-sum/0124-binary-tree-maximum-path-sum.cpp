class Solution {
public:
long long solve(TreeNode* root,long long &res){
    if(root==NULL) return 0;

    long long Lsum=max(1ll*0,solve(root->left,res));
    long long Rsum=max(1ll*0,solve(root->right,res));

   res=max(res,(Lsum+Rsum+root->val));

   return max(Lsum,Rsum)+root->val;
}
    int maxPathSum(TreeNode* root) {
        long long res=INT_MIN;
        solve(root,res);
        return res;
    }
};