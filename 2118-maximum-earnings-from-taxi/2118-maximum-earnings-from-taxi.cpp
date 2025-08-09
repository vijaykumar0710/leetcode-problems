typedef long long ll;
class Solution {
public:
int t[100001];
int binary_search(int i,int m,int end,vector<vector<int>>& rides){
   int l=i,r=m-1;
   int idx=m;
   while(l<=r){
    int mid=l+(r-l)/2;
    if(rides[mid][0]>=end){
        idx=mid;
        r=mid-1;
     }else l=mid+1;
   }
   return idx;
}
long long f(int i,int m,vector<vector<int>>& rides){
    if(i>=m) return 0;
    if(t[i]!=-1) return t[i];
    int next_idx=binary_search(i+1,m,rides[i][1],rides);
    ll take=(rides[i][1]-rides[i][0]+rides[i][2])+f(next_idx,m,rides);
    ll skip=f(i+1,m,rides);
    return t[i]=max(take,skip);
}
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end());
        int m=rides.size();
        memset(t,-1,sizeof(t));
        return f(0,m,rides);
    }
};