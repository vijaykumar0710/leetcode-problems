class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
     int res=0;
     int n=points.size();
     for(int i=0;i<n-1;i++){
       int dx=abs(points[i][0]-points[i+1][0]);
       int dy=abs(points[i][1]-points[i+1][1]);
       res+=min(dx,dy)+abs(dx-dy);
     }   
     return res;
    }
};