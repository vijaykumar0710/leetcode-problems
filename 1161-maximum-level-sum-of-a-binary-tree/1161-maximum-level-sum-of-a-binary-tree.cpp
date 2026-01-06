/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int x=1,max_sum=INT_MIN;
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        while(!q.empty()){
            int sz=q.size(),cur_sum=0;
            int level=q.front().second;
            while(sz--){
              auto node=q.front().first;
              q.pop();
              cur_sum+=node->val; 
             if(node->left) q.push({node->left,level+1});
             if(node->right) q.push({node->right,level+1});
            }
            if(max_sum<cur_sum){
                x=level;
                max_sum=cur_sum;
            }
        }
        return x;
    }
};