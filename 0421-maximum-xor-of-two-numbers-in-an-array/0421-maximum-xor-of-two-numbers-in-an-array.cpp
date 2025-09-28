class Solution {
public:
struct trieNode{ trieNode *children[2]; };
trieNode* getNode(){
    trieNode* newNode=new trieNode();
    newNode->children[0]=NULL;
    newNode->children[1]=NULL;
    return newNode;
}
void insert(int num,trieNode* root){
trieNode* crawler=root;
for(int i=31;i>=0;i--){
    int bit=(num>>i)&1;
    if(!crawler->children[bit]) crawler->children[bit]=getNode();
    crawler=crawler->children[bit];
    }
}
int getMax(int num,trieNode* root){
    trieNode* crawler=root;
    int maxi=0;
    for(int i=31;i>=0;i--){
        int bit=(num>>i)&1;
        if(crawler->children[1-bit]){
            maxi|=(1<<i); crawler=crawler->children[1-bit];
        }else crawler=crawler->children[bit];
    }
    return maxi;
}
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size(),res=0;;
        trieNode* root=getNode();
        for(auto &num:nums) insert(num,root);
        for(auto &num:nums) res=max(res,getMax(num,root));
        return res;
    }
};