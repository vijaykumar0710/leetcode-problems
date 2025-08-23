class Solution {
public:
typedef long long ll;
    int minimumArea(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        pair<int,int>min_row={m,n},max_row={0,0},max_col={0,0},min_col={m,n};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(min_row.first>i)  min_row={i,j};
                    if(max_row.first<i)  max_row={i,j};
                    if(max_col.second<j) max_col={i,j};
                    if(min_col.second>j) min_col={i,j};
                }
            }
        }
        int x1=min_row.first;
        int x2=max_row.first;
        int y3=max_col.second;
        int y4=min_col.second;
        int height=x2-x1+1;
        int weight=y3-y4+1;
        return (ll)height*weight;
    }
};