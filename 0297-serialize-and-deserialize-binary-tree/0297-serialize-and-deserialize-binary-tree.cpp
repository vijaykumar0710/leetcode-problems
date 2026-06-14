class Codec {
public:
   string s;
   void preorder(TreeNode* root){
    if(root==NULL){
        s+="#,";
        return;
    }
    s+=to_string(root->val)+",";
    preorder(root->left);
    preorder(root->right);
   }
    string serialize(TreeNode* root) {
        preorder(root);
        return s;
    }
TreeNode* build(vector<string>&s,int &idx){
    if(s[idx]=="#"){
        idx++;
        return NULL;
    }
    TreeNode* root=new TreeNode(stoi(s[idx]));
    idx++;
    root->left=build(s,idx);
    root->right=build(s,idx);
    return root;
}
    TreeNode* deserialize(string data) {
       vector<string>s;
       string temp="";
       for(auto ch:data){
        if(ch==','){
            s.push_back(temp);
            temp="";
        }else temp+=ch;
       }
       int idx=0;
       return build(s,idx);
    }
};
