class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& bui) {
        int m=bui.size(),cnt=0;
        vector<pair<int,int>>st_x(n+1,{INT_MAX,INT_MIN}),st_y(n+1,{INT_MAX,INT_MIN});
        for(auto b:bui){
            int x=b[0],y=b[1];
            st_x[x].first=min(st_x[x].first,y);
            st_x[x].second=max(st_x[x].second,y);
            st_y[y].first=min(st_y[y].first,x);
            st_y[y].second=max(st_y[y].second,x);
        }
        for(auto b:bui){
           int x=b[0],y=b[1];
           if(st_y[y].first<x && st_y[y].second>x && st_x[x].first<y && st_x[x].second>y){
            cnt++;
           }
        }
        return cnt;
    }
};