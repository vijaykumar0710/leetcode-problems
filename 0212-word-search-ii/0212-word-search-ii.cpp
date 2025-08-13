class Solution {
public:
vector<vector<int>>directions={{0,1},{1,0},{0,-1},{-1,0}};
int m,n;
vector<string>res;
struct trieNode{
    trieNode* children[26];
    string word;
    bool isEndOfWord;
};

trieNode* getNode(){
    trieNode* newNode=new trieNode();
    newNode->word="";
    newNode->isEndOfWord=false;
    for(int i=0;i<26;i++){
        newNode->children[i]=NULL;
    }
    return newNode;
}

void insert(trieNode* root,string &word){
   trieNode* crawler=root;
   for(int i=0;i<word.size();i++){
    int idx=word[i]-'a';
    if(!crawler->children[idx]) crawler->children[idx]=getNode();
    crawler=crawler->children[idx];
    }
    crawler->isEndOfWord=true;
    crawler->word=word;
}

void searchword(int i,int j,vector<vector<char>>& board,trieNode* root){
  if(i<0 || i>=m || j<0 || j>=n) return;
  if(board[i][j]=='$' || !root->children[board[i][j]-'a']) return;
  root=root->children[board[i][j]-'a'];
  if(root->isEndOfWord){
    res.push_back(root->word);
    root->isEndOfWord=false;
  }
  char temp=board[i][j];
  board[i][j]='$';
   for(auto &dir:directions){
    int n_r=i+dir[0];
    int n_c=j+dir[1];
     searchword(n_r,n_c,board,root);
   }
   board[i][j]=temp;
}

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        trieNode* root=getNode();
        for(auto &word:words) insert(root,word);

        m=board.size();
        n=board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                char ch=board[i][j];
                if(root->children[ch-'a']){
                    searchword(i,j,board,root);
                }
            }
        }
        return res;
    }
};