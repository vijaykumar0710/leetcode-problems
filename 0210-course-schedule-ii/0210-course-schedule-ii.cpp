class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>inde(numCourses,0);
        for(auto e:prerequisites){
            adj[e[1]].push_back(e[0]); 
            inde[e[0]]++; 
        }
        vector<int>res;
        queue<int>q;
        for(int i=0;i<numCourses;i++){
         if(inde[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            res.push_back(node);
            for(auto v:adj[node]){
                inde[v]--;
                if(inde[v]==0) q.push(v);
            }
        }
        for(auto in:inde) if(in!=0) return {};
        return res;
    }
};