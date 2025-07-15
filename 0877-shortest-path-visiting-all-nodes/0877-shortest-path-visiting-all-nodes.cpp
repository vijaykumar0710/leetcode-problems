class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        int N=1<<n;
        vector<vector<bool>>visited(N,vector<bool>(n,false));
        queue<tuple<int,int,int>>q;
        for(int i=0;i<n;i++){
            int mask=(1<<i);
            q.push({mask,i,0});
            visited[mask][i]=true;  
        }
        while(!q.empty()){
           auto [mask,u,steps]=q.front();
           q.pop();
           if(mask==N-1) return steps;
           for(auto &v:graph[u]){
            int newmask=mask|(1<<v);
             if(!visited[newmask][v]){
                visited[newmask][v]=true;
                q.push({newmask,v,steps+1});
             }
          }
        }
        return -1;
    }
};