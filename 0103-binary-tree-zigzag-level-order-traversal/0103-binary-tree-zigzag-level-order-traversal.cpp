class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root) return res;
        queue<pair<TreeNode*,bool>>q;
        q.push({root,true});
        while(!q.empty()){
            vector<int>temp;
            int sz=q.size();
            bool flag=q.front().second;
            while(sz--){
                TreeNode* node=q.front().first;
                q.pop();
                temp.push_back(node->val);
                if(node->left) q.push({node->left,!flag});
                if(node->right) q.push({node->right,!flag});
            }
            if(!flag) reverse(temp.begin(),temp.end());
            res.push_back(temp);
        }
        return res;
    }
};