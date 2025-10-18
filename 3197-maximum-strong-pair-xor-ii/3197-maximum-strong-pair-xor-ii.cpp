class Solution {
public:
struct trieNode{
trieNode* children[2];
int cnt;
};
trieNode* getNode(){
    trieNode* newNode=new trieNode();
    newNode->children[0]=NULL;
    newNode->children[1]=NULL;
    newNode->cnt=0;
    return newNode;
}
void insert(int num,trieNode* root){
trieNode* cr=root;
for(int i=31;i>=0;i--){
    int bit=(num>>i)&1;
    if(!cr->children[bit]) cr->children[bit]=getNode();
    cr=cr->children[bit];
    cr->cnt++;
  }
}

void remove(int num,trieNode* root){
vector<trieNode*> path;
    trieNode* cr = root;

    // Step 1: Traverse and store path
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (!cr->children[bit]) return; // number not present
        cr = cr->children[bit];
        path.push_back(cr);
    }

    // Step 2: Decrease counts
    for (auto node : path) node->cnt--;
}

int get_max(int num,trieNode* root){
trieNode* crawler=root;
 int maxi=0;
 for(int i=31;i>=0;i--){
 int bit=(num>>i)&1;
 if(crawler->children[1-bit] && crawler->children[1-bit]->cnt>0){
  maxi|=(1<<i);
  crawler=crawler->children[1-bit];
 }else crawler=crawler->children[bit];
  }
  return maxi; 
}
    int maximumStrongPairXor(vector<int>& nums) {
        int n=nums.size(),res=0;
        sort(nums.begin(),nums.end());
        trieNode* root=getNode();
        int i=0;
        for(int j=0;j<n;j++){
            insert(nums[j],root);
            while((nums[j]-nums[i])>nums[i]){
                remove(nums[i],root);
                i++;
            }
            res=max(res,get_max(nums[j],root));
        }
     return res;
    }
};