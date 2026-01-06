class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        vector<int>res;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto node=q.front();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if(i==sz-1) res.push_back(node->val);
                q.pop();
            }
        }
        return res;
    }
};