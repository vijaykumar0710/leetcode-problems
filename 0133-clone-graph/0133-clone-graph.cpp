class Solution {
public:
void f(Node* node,Node* clone_node,unordered_map<Node*,Node*>&mp){
    for(Node* v:node->neighbors){
        if(mp.find(v)==mp.end()){
            mp[v]=new Node(v->val);
            mp[node]->neighbors.push_back(mp[v]);
            f(v,mp[v],mp);
        }else mp[node]->neighbors.push_back(mp[v]);
    }
}
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        unordered_map<Node*,Node*>mp;
        mp[node]=new Node(node->val);
        f(node,mp[node],mp);
        return mp[node];
    }
};