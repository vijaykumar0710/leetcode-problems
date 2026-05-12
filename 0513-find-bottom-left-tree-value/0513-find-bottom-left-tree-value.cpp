class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        int lev = -1, res = root->val;
        q.push({root, 0});
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            if (level > lev){
                res = node->val;
                lev=level;
                }
            if (node->left)
                q.push({node->left, level + 1});
            if (node->right)
                q.push({node->right, level + 1});
        }
        return res;
    }
};