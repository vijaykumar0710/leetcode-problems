class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        unordered_map<int,vector<vector<int>>>adj;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            int st=edge[2];
            int et=edge[3];
            adj[u].push_back({v,st,et});
        }
        vector<long long>res(n,INT_MAX);
        res[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            int time=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto &v:adj[node]){
                int adjNode=v[0];
                int st=v[1];
                int et=v[2];
                if(time<st){
                    int extra_time=st-time;
                    if(time+extra_time+1<res[adjNode]){
                        res[adjNode]=time+extra_time+1;
                        pq.push({time+extra_time+1,adjNode});
                    }
                }else{
               if(time<=et && time+1<res[adjNode]){
                      res[adjNode]=time+1;
                      pq.push({time+1,adjNode});
                   }
                }
            }
        }
        if(res[n-1]==INT_MAX) return -1;
        return res[n-1];
    }
};