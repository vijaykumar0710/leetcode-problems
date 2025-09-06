class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int fp) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &e:meetings){
            int p1=e[0],p2=e[1],t=e[2];
            adj[p1].push_back({p2,t});
            adj[p2].push_back({p1,t});
        }
        vector<int>secret_time(n,INT_MAX);
        queue<pair<int,int>>q;
        secret_time[0]=0;
        secret_time[fp]=0;
        q.push({0,0});
        q.push({fp,0});
        while(!q.empty()){
            int p1=q.front().first;
            int t=q.front().second;
            q.pop();
            for(auto &neigh:adj[p1]){
               int p2=neigh.first;
               int time=neigh.second;
               if(time>=t && secret_time[p2]>time){
                secret_time[p2]=time;
                q.push({p2,time});
               }
            }
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            if(secret_time[i]!=INT_MAX) res.push_back(i);
        }
        return res;
    }
};