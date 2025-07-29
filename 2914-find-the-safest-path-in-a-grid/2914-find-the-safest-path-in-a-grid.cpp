class Solution {
public:
    vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
    int n;
    vector<vector<int>>compute_dist(vector<vector<int>>& grid){
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        queue<pair<int,int>>q;
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dist[i][j]=0;// 1 se 1 ka dist 0
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(auto &dir:directions){
                int new_r=r+dir[0];
                int new_c=c+dir[1];
                if(new_r>=0 && new_r<n && new_c>=0 && new_c<n && dist[new_r][new_c] > dist[r][c] + 1){
                    dist[new_r][new_c]=dist[r][c] + 1;
                    q.push({new_r,new_c});
                }
            }
        }
        return dist;
    }

    bool bfs(int mid,vector<vector<int>>&manhattan_dist){
         vector<vector<bool>>visited(n,vector<bool>(n,false));
         queue<pair<int,int>>q;
         if(manhattan_dist[0][0] < mid) return false;// start is unsafe important
          q.push({0,0});
        visited[0][0]=true;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            if(r==n-1 && c==n-1) return true;
            for(auto &dir:directions){
                int new_r=r+dir[0];
                int new_c=c+dir[1];
                if(new_r>=0 && new_r<n && new_c>=0 && new_c<n && !visited[new_r][new_c] && manhattan_dist[new_r][new_c]>=mid){
                    visited[new_r][new_c]=true;
                    q.push({new_r,new_c});
                }
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n=grid.size();
        vector<vector<int>>manhattan_dist=compute_dist(grid);
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return 0;
        int l=0;
        int r=2*n;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(bfs(mid,manhattan_dist)){
                ans=mid;
                l=mid+1;
            }else r=mid-1;
        }
        return ans;
    }
};