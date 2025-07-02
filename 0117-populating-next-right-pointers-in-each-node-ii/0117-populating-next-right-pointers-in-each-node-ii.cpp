class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size=q.size();
            Node* first = q.front();
            if (first->left) {
                q.push(first->left);
            }
            if (first->right) {
                q.push(first->right);
            }
            q.pop();
            size--;
            while (size--) {
                Node* node = q.front();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
                first->next = node;
                first = first->next;
                q.pop();
            }
            first->next = NULL;
        }
        return root;
    }
};