class Solution {
public:
vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
int m,n,keys=0;
int bfs(int row,int col,vector<string>& grid){
    int fullmask=(1<<keys)-1;
    vector<vector<vector<bool>>>vis((1<<keys),vector<vector<bool>>(m,vector<bool>(n,false)));
    queue<vector<int>>q;
    q.push({row,col,0,0});
    vis[0][row][col]=true;
    while(!q.empty()){
        auto vec=q.front();q.pop();
        int r=vec[0],c=vec[1],mask=vec[2],steps=vec[3];
        if(mask==fullmask) return steps;
        for(auto &dir:directions){
           int n_r=r+dir[0],n_c=c+dir[1];
           if(n_r<0 || n_c<0 || n_r>=m || n_c>=n || grid[n_r][n_c]=='#') continue;
           int new_mask=mask;
           char ch=grid[n_r][n_c];
           if(islower(ch)) new_mask|=(1<<(ch-'a'));
           else if(isupper(ch)){
            if((new_mask&(1<<(ch-'A')))==0) continue;
           }
           if(vis[new_mask][n_r][n_c]) continue;
           vis[new_mask][n_r][n_c]=true;
           q.push({n_r,n_c,new_mask,steps+1});
        }
    }
    return -1;
}
    int shortestPathAllKeys(vector<string>& grid) {
        m=grid.size(),n=grid[0].size();
        int st_r,st_c;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='@') st_r=i,st_c=j;
                if(islower(grid[i][j])) keys++;
            }
        }
        return bfs(st_r,st_c,grid);
    }
};