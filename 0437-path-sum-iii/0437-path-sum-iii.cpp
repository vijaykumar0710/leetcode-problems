class Solution {
public:
unordered_map<long long,int>mp;
int cnt=0;
void dfs(TreeNode* root, long long curr_sum,int k){
  if(!root) return;
  curr_sum+=root->val;
  if(curr_sum==k) cnt++;
  cnt+=mp[curr_sum-k];
  mp[curr_sum]++;
  dfs(root->left,curr_sum,k);
  dfs(root->right,curr_sum,k);
  mp[curr_sum]--;
}
    int pathSum(TreeNode* root, int targetSum) {
       dfs(root,0,targetSum);
       return cnt;
    }
};