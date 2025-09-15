class Solution {
public:
bool isPossible(vector<int>& time,long long mid,long long totalTrips){
    long long trips=0LL;
    for(auto &t:time){
        trips=(long long)trips+mid/t;
        if(trips>=totalTrips) return true;
    }
    return false;
}
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n=time.size();
        long long l=*min_element(time.begin(),time.end());
        long long r=1e15;
        long long res=1;
        while(l<=r){
            long long mid=(long long)l+(r-l)/2;
            if(isPossible(time,mid,totalTrips)){
                res=mid;
                r=mid-1;
            }else l=mid+1;
        }
        return res;
    }
};