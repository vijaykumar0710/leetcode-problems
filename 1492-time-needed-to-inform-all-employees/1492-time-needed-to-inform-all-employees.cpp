class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>adj(n);
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(i==headID) continue;
            adj[i].push_back(informTime[i]);
            adj[informTime[i]].push_back(i);
        }
        int res=INT_MAX;
        queue<pair<int,int>>q;
        visited[headID]=true;
        q.push({headID,informTime[headID]});
        while(!q.empty()){
          int sz=q.size();
          int min_time=INT_MAX;
          while(sz--){
            auto [node,time]=q.front();
            q.pop();
            min_time=min(min_time,time);
            res=min(res,min_time);
            for(auto &v:adj[node]){
                if(visited[v]) continue;
                visited[v]=true;
                q.push({v,min_time+informTime[v]});
             }
           }
        }
        return res;
    }
};