class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_map<int,vector<int>>adj;
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        unordered_set<int>st(restricted.begin(),restricted.end());
        int res=1;
        queue<int>q;
        q.push(0);
        st.insert(0);
        while(!q.empty()){
            int u=q.front();q.pop();
            for(auto &v:adj[u]){
                if(st.count(v)) continue;
                res++;
                st.insert(v);
                q.push(v);
            }
        }
        return res;
    }
};