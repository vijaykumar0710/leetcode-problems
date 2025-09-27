class Solution {
public:
int m,n;
int t[71][71][71];
int f(int i,int j1,int j2,vector<vector<int>>& grid){
if(i<0 || j1<0 || j2<0 || i>=m || j1>=n || j2>=n) return -1e8;
if(i>=m-1){
    if(j1==j2) return grid[i][j1];
    return grid[i][j1]+grid[i][j2];
   }
   if(t[i][j1][j2]!=-1) return t[i][j1][j2];
  int cherries=-1e8;
  for(int x=-1;x<=1;x++){
    for(int y=-1;y<=1;y++){
        int val=0;
        if(j1==j2) val=grid[i][j1];
        else val=grid[i][j1]+grid[i][j2];
        val+=f(i+1,j1+x,j2+y,grid);
        cherries=max(cherries,val);
        }
     }
  return t[i][j1][j2]=cherries;
}
    int cherryPickup(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        memset(t,-1,sizeof(t));
        return f(0,0,n-1,grid);
    }
};