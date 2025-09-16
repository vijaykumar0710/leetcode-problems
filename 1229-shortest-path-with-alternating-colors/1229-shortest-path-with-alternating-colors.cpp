class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>>adjRed(n),adjBlue(n);
        for(auto &e:redEdges)  adjRed[e[0]].push_back(e[1]);
        for(auto &e:blueEdges) adjBlue[e[0]].push_back(e[1]);
        vector<vector<int>>t(n,vector<int>(2,INT_MAX));
        t[0][0]=0,t[0][1]=0;
        queue<pair<int,int>>q;
        q.push({0,0});
        q.push({0,1});
        while(!q.empty()){
            int node=q.front().first;
            int color=q.front().second;
            int dist=t[node][color];
            q.pop();
            if(color==0){
                for(auto &v:adjBlue[node]){
                    if(t[v][1]==INT_MAX){ 
                    t[v][1]=min(t[v][1],dist+1);
                    q.push({v,1});
                    }
                }
            }else{
                for(auto &v:adjRed[node]){
                    if(t[v][0]==INT_MAX){ 
                    t[v][0]=min(t[v][0],dist+1);
                    q.push({v,0});
                    }
                }
            }
        }
        vector<int>res(n,-1);
         for(int i=0;i<n;i++){
            int shortest=min(t[i][0],t[i][1]);
            if(shortest!=INT_MAX) res[i]=shortest;
         }
         return res;
    }
};