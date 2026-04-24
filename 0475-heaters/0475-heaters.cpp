class Solution {
public:
bool isValid(int mid,vector<int>& houses, vector<int>& heaters){
    int n=houses.size(),m=heaters.size();
    int st=heaters[0]-mid,end=mid+heaters[0];
    for(int i=1;i<m;i++){
       if(end-(heaters[i]-mid)>=-1){
        end=mid+heaters[i];
       }
    }
    return st<=1 && end>=houses[n-1];
}
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n=houses.size(),m=heaters.size();
        int res=0;
        int l=0,r=max(heaters[m-1],houses[n-1]);
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(mid,houses,heaters)){
                res=mid;
                r=mid-1;
            }else l=mid+1;
        }
        return res;
    }
};