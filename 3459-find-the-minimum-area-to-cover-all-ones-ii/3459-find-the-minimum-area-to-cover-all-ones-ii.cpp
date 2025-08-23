class Solution {
public:
vector<vector<int>>rotate_grid(vector<vector<int>>&grid){
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>>rotated_grid(n,vector<int>(m));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            rotated_grid[j][m-i-1]=grid[i][j];
        }
    }
    return rotated_grid;
}
 int min_area(int st_row,int end_row,int st_col,int end_col,vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        pair<int,int>min_row={m,n},max_row={0,0},max_col={0,0},min_col={m,n};
        for(int i=st_row;i<end_row;i++){
            for(int j=st_col;j<end_col;j++){
                if(grid[i][j]==1){
                    if(min_row.first>i)  min_row={i,j};
                    if(max_row.first<i)  max_row={i,j};
                    if(max_col.second<j) max_col={i,j};
                    if(min_col.second>j) min_col={i,j};
                }
            }
        }
        int x1=min_row.first,y1=min_row.second;
        int x2=max_row.first,y2=max_row.second;
        int x3=max_col.first,y3=max_col.second;
        int x4=min_col.first,y4=min_col.second;
        int height=x2-x1+1;
        int weight=y3-y4+1;
        return height*weight;
    }
int utility(vector<vector<int>>&grid){
    int m=grid.size();
    int n=grid[0].size();
    int area=INT_MAX;

    for(int row=1;row<m;row++){
        for(int col=1;col<n;col++){
            int top_left=min_area(0,row,0,col,grid);
            int top_right=min_area(0,row,col,n,grid);
            int bottom=min_area(row,m,0,n,grid);

            area=min(area,top_left+top_right+bottom);

            int top=min_area(0,row,0,n,grid);
            int bottom_left=min_area(row,m,0,col,grid);
            int bottom_right=min_area(row,m,col,n,grid);

            area=min(area,top+bottom_left+bottom_right);
        }
    }

    for(int row_spilt1=1;row_spilt1<m;row_spilt1++){
        for(int row_spilt2=row_spilt1+1;row_spilt2<m;row_spilt2++){
            int top=min_area(0,row_spilt1,0,n,grid);
            int middle=min_area(row_spilt1,row_spilt2,0,n,grid);
            int bottom=min_area(row_spilt2,m,0,n,grid);

            area=min(area,top+middle+bottom);
        }
    }
    return area;
}
    int minimumSum(vector<vector<int>>& grid) {
        int res=utility(grid);
        vector<vector<int>>rotated_grid=rotate_grid(grid);
        res=min(res,utility(rotated_grid));
        return res;
    }
};