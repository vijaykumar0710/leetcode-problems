class Solution {
public:
struct trieNode{
   trieNode* children[10];
   bool isEndofWord;
};
trieNode* getNode(){
    trieNode *newNode=new trieNode();
    newNode->isEndofWord=false;
    for(int i=0;i<10;i++){
        newNode->children[i]=NULL;
    }
    return newNode;
}

void insert(string &word,trieNode* root){
  trieNode* crawler=root;
  for(int i=0;i<word.size();i++){
    int idx=word[i]-'0';
    if(!crawler->children[idx]){
        crawler->children[idx]=getNode();
    }
    crawler=crawler->children[idx];
  }
  crawler->isEndofWord=true;
}
int prefix(trieNode* root,string &word){
    trieNode* crawler=root;
    int len=0;
    for(int i=0;i<word.size();i++){
        int idx=word[i]-'0';
        if(crawler->children[idx]){
           crawler=crawler->children[idx];
           len++;
        }else{
          break;
        }
    }
    return len;
}
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        trieNode* root=getNode();
        int lcp=0;
        for(auto &num:arr1){
            string word=to_string(num);
            insert(word,root);
        }
         for(auto &num:arr2){
            string str=to_string(num);
            lcp=max(lcp,prefix(root,str));
         }
         return lcp;
    }
};