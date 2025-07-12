class Solution {
public:
unordered_map<string,multiset<string>>adj;
 vector<string>res;
void dfs(string u){
    auto &st=adj[u];
    while(!st.empty()){
        string v=*st.begin();
       st.erase(st.begin());
       dfs(v);
    }
    res.push_back(u);
}
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &ticket:tickets){
            string u=ticket[0];
            string v=ticket[1];
            adj[u].insert(v);
        }
       dfs("JFK");
       reverse(res.begin(),res.end());
        return res;
    }
};