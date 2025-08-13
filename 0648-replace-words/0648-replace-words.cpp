class Solution {
public:
struct trieNode{
trieNode* children[26];
bool isEndofWords;
};

trieNode* getNode(){
    trieNode *newNode=new trieNode();
    bool isEndofWords=false;
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
    if(!crawler->children[idx]){
        crawler->children[idx]=getNode();
    }
   crawler=crawler->children[idx];
  }
  crawler->isEndofWords=true;
}

string search(string &word){
    trieNode* crawler=root;
    for(int i=0;i<word.size();i++){
      int idx=word[i]-'a';
      if(!crawler->children[idx]){
        return word;
      }
      crawler=crawler->children[idx];
      if(crawler->isEndofWords) return word.substr(0,i+1);
    }
    return word;
}
    string replaceWords(vector<string>& dictionary, string sentence) {
        root=getNode();
        for(auto &dic:dictionary){ 
        insert(dic);
        }
        stringstream ss(sentence);
        string res;
        string token;
        while(getline(ss,token,' ')){
               res+=search(token)+' ';
        }
        return res.substr(0,res.size()-1);
    }
};