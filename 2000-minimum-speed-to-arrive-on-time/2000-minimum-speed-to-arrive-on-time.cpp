class Solution {
public:
bool isPossible(vector<int>& dist, double hour,double mid){
    int n=dist.size();
    double time=0.0;
    for(int i=0;i<n-1;i++){
        time+=ceil(dist[i]/mid);
        if(time>hour) return false;
    }
    time+=(double)dist[n-1]/mid;
    return time<=hour;
}
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        int l=1;
        int r=1e7;
        int res=INT_MAX;
        while(l<=r){
            double mid=l+(r-l)/2;
            if(isPossible(dist,hour,mid)){
                res=mid;
                r=mid-1;
            }else l=mid+1;
        }
        return res==INT_MAX?-1:res;
    }
};