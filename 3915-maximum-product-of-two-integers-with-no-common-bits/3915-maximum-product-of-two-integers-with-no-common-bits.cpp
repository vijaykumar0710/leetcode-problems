class Solution {
public:
struct trieNode{
trieNode* children[2];
};
trieNode* getNode(){
trieNode* newNode=new trieNode();
newNode->children[0]=NULL;
newNode->children[1]=NULL;
return newNode;
}
void insert(int num,trieNode* root){
trieNode* cr=root;
for(int i=31;i>=0;i--){
    int bit=(num&(1<<i))?1:0;
    if(!cr->children[bit])cr->children[bit]=getNode();
    cr=cr->children[bit];
}
}
int f(trieNode* cr,int mask,int i,int num){
    if(!cr) return -1;
    if(i<0){
        return mask;
        }
    int bit=(num>>i)&1;
    if(bit==1){
        return f(cr->children[0],mask,i-1,num);
    }else{
        int left,right;
        left=f(cr->children[1],mask|(1<<i),i-1,num);
        if(left!=-1) return left;
        right=f(cr->children[0],mask,i-1,num);
        return right;
    }
}
long long get_max(int num,trieNode* root){
trieNode* cr=root;
int mask=0;
int maxi=f(cr,mask,31,num);
return (long long)maxi*num;
}
    long long maxProduct(vector<int>& nums) {
        int n=nums.size();
        trieNode* root=getNode();
        long long res=0ll;
        insert(nums[0],root);
        for(int i=1;i<n;i++){
            res=max(res,get_max(nums[i],root));
            insert(nums[i],root);
        }
        return (long long)res;
    }
};