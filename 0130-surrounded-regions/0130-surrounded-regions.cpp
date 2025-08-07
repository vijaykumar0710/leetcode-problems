class Solution {
public:
vector<vector<int>>direction={{0,1},{0,-1},{1,0},{-1,0}};
int m,n;

void bfs1(int i,int j,vector<vector<char>>& board,vector<vector<bool>>visited){
   queue<pair<int,int>>q;
   visited[i][j]=true;
   q.push({i,j});
   board[i][j]='$';
   while(!q.empty()){
    int r=q.front().first;
    int c=q.front().second;
    q.pop();
    for(auto &dir:direction){
        int n_r=r+dir[0];
        int n_c=c+dir[1];
        if(n_r>=0 && n_r<m && n_c>=0 && n_c<n && !visited[n_r][n_c] && board[n_r][n_c]=='O'){
            board[n_r][n_c]='$';
            visited[n_r][n_c]=true;
            q.push({n_r,n_c});
        }
      }
   }
}

void bfs(int i,int j,vector<vector<char>>& board,vector<vector<bool>>visited){
   queue<pair<int,int>>q;
   visited[i][j]=true;
   q.push({i,j});
   board[i][j]='X';
   while(!q.empty()){
    int r=q.front().first;
    int c=q.front().second;
    q.pop();
    for(auto &dir:direction){
        int n_r=r+dir[0];
        int n_c=c+dir[1];
        if(n_r>=0 && n_r<m && n_c>=0 && n_c<n && !visited[n_r][n_c] && board[n_r][n_c]=='O'){
            board[n_r][n_c]='X';
            visited[n_r][n_c]=true;
            q.push({n_r,n_c});
        }
      }
   }
}

void bfs2(int i,int j,vector<vector<char>>& board,vector<vector<bool>>visited){
   queue<pair<int,int>>q;
   visited[i][j]=true;
   q.push({i,j});
   board[i][j]='O';
   while(!q.empty()){
    int r=q.front().first;
    int c=q.front().second;
    q.pop();
    for(auto &dir:direction){
        int n_r=r+dir[0];
        int n_c=c+dir[1];
        if(n_r>=0 && n_r<m && n_c>=0 && n_c<n && !visited[n_r][n_c] && board[n_r][n_c]=='$'){
            board[n_r][n_c]='O';
            visited[n_r][n_c]=true;
            q.push({n_r,n_c});
        }
      }
   }
}


    void solve(vector<vector<char>>& board) {
         m=board.size();
         n=board[0].size();

         vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int j=0;j<n;j++){
            if(board[0][j]=='O' && !visited[0][j]) bfs1(0,j,board,visited);
            if(board[m-1][j]=='O'&& !visited[m-1][j]) bfs1(m-1,j,board,visited);
        }
        for(int i=0;i<m;i++){
            if(board[i][0]=='O' && !visited[i][0]) bfs1(i,0,board,visited);
            if(board[i][n-1]=='O' && !visited[i][n-1]) bfs1(i,n-1,board,visited);;
        }

        vector<vector<bool>>visited1(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited1[i][j] && board[i][j]=='O')
                    bfs(i,j,board,visited1);
            }
        }

        vector<vector<bool>>visited2(m,vector<bool>(n,false));
         for(int j=0;j<n;j++){
            if(board[0][j]=='$' && !visited2[0][j]) bfs2(0,j,board,visited);
            if(board[m-1][j]=='$' && !visited2[m-1][j]) bfs2(m-1,j,board,visited);
        }
        for(int i=0;i<m;i++){
            if(board[i][0]=='$' && !visited[i][0]) bfs2(i,0,board,visited);
            if(board[i][n-1]=='$' && !visited[i][n-1]) bfs2(i,n-1,board,visited);;
        }
    }
};