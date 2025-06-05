class Solution {
public:
  int find(int i,vector<int>&parent){
    if(i==parent[i]) return i;
    return parent[i]=find(parent[i],parent);
  }
  void Union(int x,int y,vector<int>&parent){
    int x_parent=find(x,parent);
    int y_parent=find(y,parent);
    if(x_parent==y_parent) return;
    if(x_parent<y_parent){
        parent[y_parent]=x_parent;
    }else{
        parent[x_parent]=y_parent;
    }
  }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.size();
        vector<int>parent(26);
        for(int i=0;i<26;i++)
           parent[i]=i;
        for(int i=0;i<n;i++){
            Union(s1[i]-'a',s2[i]-'a',parent);
        }
       string res;
       for(auto &ch:baseStr){
           res+=(char)find(ch-'a',parent)+'a';
       }
       return res;
    }
};