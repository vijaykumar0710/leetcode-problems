class Solution {
public:
char dfs(unordered_map<char,vector<char>>&adj,char ch,vector<int>&visited){
    if(visited[ch-'a']==1) return ch;
    visited[ch-'a']=1;
    char minChar=ch;
    for(auto &v:adj[minChar]){
         if(visited[v-'a']==0){
            minChar=min(minChar,dfs(adj,v,visited));
         }
    }
    return minChar;
}
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.size();
        unordered_map<char,vector<char>>adj;
        for(int i=0;i<n;i++){
            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
        }
        string res="";
        for(auto &ch:baseStr){
            vector<int>visited(26,0);
            char minChar=dfs(adj,ch,visited);
            res+=minChar;
        }
        return res;
    }
};