class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int,vector<pair<int,int>>>mp;
        for(auto &e:meetings){
          int u=e[0],v=e[1],t=e[2];
          mp[t].push_back({u,v});
        }
        vector<bool>visited(n,false);
        visited[0]=true,visited[firstPerson]=true;
        for(auto &it:mp){
            int key=it.first;
            auto vec=it.second;
            unordered_map<int,vector<int>>adj;
            unordered_set<int>seen;
            queue<int>q;
            for(auto &[p1,p2]:vec){
                adj[p1].push_back(p2);
                adj[p2].push_back(p1);
                if(visited[p1] && seen.count(p1)==0) q.push(p1),seen.insert(p1);
                if(visited[p2] && seen.count(p2)==0) q.push(p2),seen.insert(p2);
            }
            while(!q.empty()){
                int u=q.front();
                q.pop();
                for(auto &v:adj[u]){
                    if(!visited[v]){
                        visited[v]=true;
                        q.push(v);
                    }
                }
            }
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            if(visited[i]) res.push_back(i);
        }
        return res;
    }
};