class Solution {
public:
struct trieNode{
    trieNode* children[26];
    int cnt;
};

trieNode* getNode(){
    trieNode* newNode=new trieNode();
    newNode->cnt=0;
    for(int i=0;i<26;i++){
        newNode->children[i]=NULL;
    }
    return newNode;
}

trieNode *root;

void insert(string &word){
trieNode* crawler=root;
for(int i=0;i<word.size();i++){
    int idx=word[i]-'a';
    if(!crawler->children[idx]) crawler->children[idx]=getNode();
    crawler=crawler->children[idx];
    crawler->cnt++;
   }
}

int prefix(string &word){
    trieNode* crawler=root;
    int i=0;
   for(;i<word.size();i++){
     int idx=word[i]-'a';
     if(!crawler->children[idx]) return 0;
    crawler=crawler->children[idx];
  }
 return crawler->cnt;
}
    int prefixCount(vector<string>& words, string pref) {
       root=getNode();
       for(auto &word:words) insert(word);
       return prefix(pref);
    }
};