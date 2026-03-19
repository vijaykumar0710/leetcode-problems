class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int res=0;
        vector<vector<pair<int,int>>>p(m+1,vector<pair<int,int>>(n+1,{0,0}));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int x_cnt=(grid[i][j]=='X'?1:0)+p[i][j+1].first+p[i+1][j].first-p[i][j].first;
                int y_cnt=(grid[i][j]=='Y'?1:0)+p[i][j+1].second+p[i+1][j].second-p[i][j].second;
                p[i+1][j+1].first=x_cnt;
                p[i+1][j+1].second=y_cnt;
                if(x_cnt>0 && x_cnt==y_cnt) res++;
            }
        }
        return res;
    }
};