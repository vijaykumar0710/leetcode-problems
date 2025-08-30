class Solution {
public:
int n;
unordered_map<int,vector<int>>mp;
    int minJumps(vector<int>& arr) {
        n=arr.size();
        for(int i=0;i<n;i++) mp[arr[i]].push_back(i);
        vector<bool>visited(n,false);
        queue<pair<int,int>>q;
        visited[0]=true;
        q.push({0,0});
        while(!q.empty()){
            auto node=q.front();q.pop();
            int u=node.first;
            int steps=node.second;
            if(u==n-1) return steps;
            if(u+1<n && !visited[u+1]){
                visited[u+1]=true;
                q.push({u+1,steps+1});
            }
            if(u-1>=0 && !visited[u-1]){
                visited[u-1]=true;
                q.push({u-1,steps+1});
            }
            auto &vec=mp[arr[u]];
            for(auto &idx:vec){
             if(u!=idx && idx<n && !visited[idx]){
               visited[idx]=true;
                q.push({idx,steps+1});
                }
               vec.clear();
             }
        }
        return -1;
    }
};