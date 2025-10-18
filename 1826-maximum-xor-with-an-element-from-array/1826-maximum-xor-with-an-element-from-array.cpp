class Solution {
public:
struct trieNode{ trieNode *children[2]; };
trieNode *getNode(){
    trieNode *newNode=new trieNode();
    newNode->children[0]=NULL;
    newNode->children[1]=NULL;
    return newNode;
}
void insert(int num ,trieNode* root){
 trieNode* crawler=root;
 for(int i=31;i>=0;i--){
 int bit=num&(1<<i)?1:0;
 if(!crawler->children[bit]) crawler->children[bit]=getNode();
 crawler=crawler->children[bit];
  }
}
int get_max(int num,trieNode* root){
 trieNode* crawler=root;
 int maxi=0;
 for(int i=31;i>=0;i--){
 int bit=num&(1<<i)?1:0;
 if(crawler->children[1-bit]){
  maxi|=(1<<i);
  crawler=crawler->children[1-bit];
 }else crawler=crawler->children[bit];
  }
  return maxi;
}
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>temp;
        for(int i=0;i<queries.size();i++){
           int x=queries[i][0],m=queries[i][1];
           temp.push_back({m,x,i});
        }
        sort(temp.begin(),temp.end());
        int n=nums.size(),idx=0;
        vector<int>res(queries.size());
        trieNode* root=getNode();
        for(int i=0;i<temp.size();i++){
          int x=temp[i][1],m=temp[i][0],index=temp[i][2];
          if(nums[0]>m){
            res[index]=-1;
            continue;
          }
          while(idx<n && nums[idx]<=m){
            insert(nums[idx],root);
            idx++;
          }
          int maxi=get_max(x,root);
          res[index]=maxi;
        }
        return res;
    }
};