class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });
        int n=points.size();
        int last_balloons_burst=points[0][1];
        int arrow=1;
        for(int i=1;i<n;i++){
            if(points[i][0]>last_balloons_burst){
               arrow++;
               last_balloons_burst=points[i][1];
            }
        }
        return arrow;
    }
};