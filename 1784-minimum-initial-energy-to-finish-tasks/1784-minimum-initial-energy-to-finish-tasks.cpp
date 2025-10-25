class Solution {
public:
bool isPossible(vector<vector<int>>& tasks,int mid){
    int n=tasks.size();
    for(int i=0;i<n;i++){
        int act=tasks[i][0];
        int mini=tasks[i][1];
        if(mini>mid) return false;
        mid-=act;
    }
    return true;
}
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](auto &a,auto &b){
         return (a[1]-a[0])>(b[1]-b[0]);
        });
        int l=0,r=1e9;
        int res=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(tasks,mid)){
                res=mid;
                r=mid-1;
            }else l=mid+1;
        }
        return res;
    }
};