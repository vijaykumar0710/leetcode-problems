class Solution {
public:
char bfs(unordered_map<char,vector<char>>&adj,char ch){
    vector<int>visited(26,0);
    queue<char>q;
    q.push(ch);
    visited[ch-'a']=1;
    char minChar=ch;
    while(!q.empty()){
        char u=q.front();
        q.pop();
        minChar=min(minChar,u);
        for(auto &v:adj[u]){
            if(visited[v-'a']==0){
                q.push(v);
                visited[v-'a']=1;
            }
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
            char minChar=bfs(adj,ch);
            res+=minChar;
        }
        return res;
    }
};