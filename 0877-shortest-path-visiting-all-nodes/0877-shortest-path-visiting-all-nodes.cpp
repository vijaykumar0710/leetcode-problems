class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        int N=(1<<n)-1;
        queue<vector<int>>q;
        vector<vector<bool>>visited(1<<n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            int mask=1<<i;
            q.push({i,mask,0});
            visited[mask][i]=true;
        }
        while(!q.empty()){
            auto vec=q.front();q.pop();
            int node=vec[0];
            int mask=vec[1];
            int len=vec[2];
            if(mask==N) return len;
            for(auto &v:graph[node]){
                int new_mask=mask|(1<<v);
                if(!visited[new_mask][v]){
                    visited[new_mask][v]=true;
                    q.push({v,new_mask,len+1});
                }
            }
        }
        return -1;
    }
};