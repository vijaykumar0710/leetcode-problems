class Solution {
public:
bool isPossible(vector<int>& position, int m,int mid){
    int n=position.size();
    m--;
    int prev=0;
    for(int i=1;i<n;i++){
       if(position[i]-position[prev]>=mid){
        m--;
        prev=i;
       }
    }
    return m<=0;
}
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int res=-1;
        int l=0,r=position[n-1]-position[0];
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(position,m,mid)){
                res=mid;
                l=mid+1;
            }else r=mid-1;
        }
        return res;
    }
};