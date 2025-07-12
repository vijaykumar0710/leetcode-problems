class Solution {
public:
unordered_map<string,priority_queue<string,vector<string>,greater<string>>>adj;
 vector<string>res;
void dfs(string u){
    auto &pq=adj[u];
    while(!pq.empty()){
        string v=pq.top();
       pq.pop();
       dfs(v);
    }
    res.push_back(u);
}
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &ticket:tickets){
            string u=ticket[0];
            string v=ticket[1];
            adj[u].push(v);
        }
       dfs("JFK");
       reverse(res.begin(),res.end());
        return res;
    }
};