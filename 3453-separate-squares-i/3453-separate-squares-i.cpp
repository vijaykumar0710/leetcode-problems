class Solution {
public:
int n;
bool cal_area(vector<vector<int>>& squares,double mid){
  double area1=0.0,area2=0.0;
  for(int i=0;i<n;i++){
    double y=squares[i][1],l=squares[i][2];
    double lower=y,upper=y+l;
    if(lower>mid){
     area1+=(double)l*l;
    }else if(upper<mid){
     area2+=(double)l*l;
    }else{
     area2+=(double)(mid-lower)*l;
     area1+=(double)(upper-mid)*l;
    }
  }
  return area1>area2;
}
    double separateSquares(vector<vector<int>>& squares) {
        n=squares.size();
        double l=0.0,r=2e9;
        double res=0.0;
        while((r-l)>1e-5){
            double mid=l+(r-l)/2.0;
            if(cal_area(squares,mid)){
                l=mid;
            }else{
                res=mid;
                r=mid;
            }
        }
        return res;
    }
};