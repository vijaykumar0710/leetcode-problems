class Solution {
public:
int keys_cnt=0;
vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
int bfs(int row,int col,vector<string>&grid,int m,int n){
    int full_mask=(1<<keys_cnt)-1;

    vector<vector<vector<bool>>>visited(m,vector<vector<bool>>(n,vector<bool>(1<<keys_cnt,false)));
    queue<tuple<int,int,int,int>>q;

    q.push({row,col,0,0});
    visited[row][col][0]=true;

    while(!q.empty()){
        auto [r,c,mask,steps]=q.front();
        q.pop();

        if(mask==full_mask) return steps;

        for(auto &dir:directions){
            int n_r=r+dir[0];
            int n_c=c+dir[1];

           if(n_r<0 || n_c<0 || n_r>=m || n_c>=n) continue;
           char ch=grid[n_r][n_c];

           if(ch=='#') continue;

           int new_mask=mask;
           if(islower(ch)){
            int bit=ch-'a';
            new_mask|=(1<<bit);
           }

           if(isupper(ch)){
            int bit=ch-'A';
            if((new_mask&(1<<bit))==0) continue;
           }

           if(!visited[n_r][n_c][new_mask]){
            visited[n_r][n_c][new_mask]=true;
            q.push({n_r,n_c,new_mask,steps+1});
           }
        }
    }
    return -1;
}
    int shortestPathAllKeys(vector<string>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int st_row,st_col;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='@'){
                    st_row=i;
                    st_col=j;
                }
                if(islower(grid[i][j])) keys_cnt++;
            }
        }
     return bfs(st_row,st_col,grid,m,n);
    }
};