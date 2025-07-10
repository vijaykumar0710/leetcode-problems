class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n=coins.size();
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(n);
        for(auto &e:edges){
         adj[e[0]].push_back(e[1]);
         adj[e[1]].push_back(e[0]);
         indegree[e[0]]++;
         indegree[e[1]]++;
        }
        vector<bool>deleted(n,false);
        queue<int>q;
        for(int i=0;i<n;i++){
           if(indegree[i]==1 && coins[i]==0 && !deleted[i]){
            q.push(i);
           }
        }
        while(!q.empty()){
            int node=q.front();
            deleted[node]=true;
            q.pop();
            for(auto &neigh:adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==1 && coins[neigh]==0 && !deleted[neigh]){
                    q.push(neigh);
                }
            }
        }
        for(int t=0;t<2;t++){
            queue<int>q;
           for(int i=0;i<n;i++){
            if(indegree[i]==1 && !deleted[i])
               q.push(i);
           }
           while(!q.empty()){
            int node=q.front();
            deleted[node]=true;
            q.pop();
            for(auto &neigh:adj[node]){
                indegree[neigh]--;
             }
           }
        }
        int res=0;
        for(auto &e:edges){
            if(!deleted[e[0]] && !deleted[e[1]])
               res+=2;
        }
        return res;
    }
};