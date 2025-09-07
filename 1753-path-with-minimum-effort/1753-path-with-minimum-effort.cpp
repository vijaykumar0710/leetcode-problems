class Solution {
public:
int m,n;
vector<vector<int>>directions={{0,1},{1,0},{0,-1},{-1,0}};
int isPossible(int r,int c,int diff,vector<vector<int>>&grid){
vector<vector<bool>>visited(m,vector<bool>(n,false));
queue<pair<int,int>>q;
q.push({r,c});
visited[r][c]=true;
while(!q.empty()){
     auto [row,col]=q.front();
     q.pop();
     if(row==m-1 && col==n-1) return true;
     for(auto &dir:directions){
        int n_r=row+dir[0],n_c=col+dir[1];
        if(n_r<0 || n_r>=m || n_c<0 || n_c>=n || visited[n_r][n_c] || abs(grid[n_r][n_c]-grid[row][col])>diff) continue;
        visited[n_r][n_c]=true;
        q.push({n_r,n_c});
     }
  }
  return false;
}
    int minimumEffortPath(vector<vector<int>>& heights) {
         m=heights.size();
         n=heights[0].size();
        int diff=INT_MAX;
        int l=0,r=1e6;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(0,0,mid,heights)){
                diff=mid;
                r=mid-1;
            }else l=mid+1;
        }
        return diff;
    }
};