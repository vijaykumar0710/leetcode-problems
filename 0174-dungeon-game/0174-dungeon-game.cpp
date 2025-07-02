class Solution {
public:
    int m, n;
    vector<vector<int>>directions={{0,1},{1,0}};
    unordered_map<string,bool>t;
    bool solve(vector<vector<int>>& grid,int row,int col,int mid){
    if( row>=m || col>=n) return false;
    mid+=grid[row][col];
    if(mid<=0) return false;
    if(row==m-1 && col==n-1) return true;
    string key=to_string(row)+"&"+to_string(col)+"&"+to_string(mid);
    if(t.find(key)!=t.end()) return t[key];
    for(auto &dir:directions){
        int new_r=dir[0]+row;
        int new_c=dir[1]+col;
       if(solve(grid,new_r,new_c,mid)) return t[key]=true;
    }
    return t[key]=false;
    }
    int calculateMinimumHP(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int l=1;
        int r=4*1e7;
        int res=4*1e7;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(solve(grid,0,0,mid)){
                res=min(res,mid);
                r=mid-1;
            }
            else l=mid+1;
        }
        return res;
    }
};