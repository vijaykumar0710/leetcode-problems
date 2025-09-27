class Solution {
public:
double cal_area(auto &p1,auto &p2,auto &p3){
    int x1=p1.first,y1=p1.second;
    int x2=p2.first,y2=p2.second;
    int x3=p3.first,y3=p3.second;
    return (double)0.5*abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
}
    double largestTriangleArea(vector<vector<int>>& points) {
        int n=points.size();
        double max_area=0.0;
        for(int i=0;i<=n-3;i++){
            for(int j=i+1;j<=n-2;j++){
                for(int k=j+1;k<n;k++){
                    pair<int,int>p1={points[i][0],points[i][1]};
                    pair<int,int>p2={points[j][0],points[j][1]};
                    pair<int,int>p3={points[k][0],points[k][1]};
                    max_area=max(max_area,cal_area(p1,p2,p3));
                }
            }
        }
        return max_area;
    }
};