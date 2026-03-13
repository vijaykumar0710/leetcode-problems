class Solution {
public:
int f(long long mid,int num,int mh){
    long long l=1,r=mh;
    long long res=0;
    while(l<=r){
        long long lund=l+(r-l)/2;
         if((1ll*lund*(lund+1))/2<=(mid/num)){
            res=lund;
            l=lund+1;
         }else r=lund-1;
    }
    return res;
}
bool check(long long mid,int mh,vector<int>&wt){
    long long res=0;
    for(auto num:wt){
        long long x=f(mid,num,mh);
        res+=x;
    }
    return res>=mh;
}
    long long minNumberOfSeconds(int mh, vector<int>& wt) {
        int n=wt.size();
        long long res=INT_MAX;
        long long l=1,r=1e16;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(check(mid,mh,wt)){
                res=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return res;
    }
};