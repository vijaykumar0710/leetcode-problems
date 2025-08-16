class Solution {
public:
int res=-1;
void dfs(int i,vector<int>& edges,vector<int>&count,vector<bool>&visited,vector<bool>&inRecursion){
    if(i!=-1){
        visited[i]=true;
        inRecursion[i]=true;
        int v=edges[i];
        if(v!=-1 &&!visited[v]){
            count[v]=count[i]+1;
            dfs(v,edges,count,visited,inRecursion);
        }else if(v!=-1 && inRecursion[v]){
             int cycle_size=count[i]-count[v]+1;
             res=max(res,cycle_size);
        }
        inRecursion[i]=false;
    }
}
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>count(n,1);
        vector<bool>visited(n,false),inRecursion(n,false);
        for(int i=0;i<n;i++){
            if(edges[i]!=-1 && !visited[i]){  
                dfs(i,edges,count,visited,inRecursion);
              }
        }
        return res;
    }
};