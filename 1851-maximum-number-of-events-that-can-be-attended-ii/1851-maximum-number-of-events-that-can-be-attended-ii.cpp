class Solution {
public:
int binarySearch(int i,int endTime,vector<vector<int>>& events){
    int l=i,r=events.size()-1;
    int idx=events.size();
    while(l<=r){
        int mid=l+(r-l)/2;
        if(events[mid][0]>endTime){
            idx=mid;
            r=mid-1;
        }else l=mid+1;
    }
    return idx;
}

int f(int i,int k,vector<vector<int>>& events,int n,vector<vector<int>>&t){
    if(k==0 || i==n) return 0;

    if(t[i][k]!=-1) return t[i][k];

    int nextIdx=binarySearch(i+1,events[i][1],events);
    int take=events[i][2]+f(nextIdx,k-1,events,n,t);

    int skip=f(i+1,k,events,n,t);
    return t[i][k]=max(take,skip);
}
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int n=events.size();
        vector<vector<int>>t(n+1,vector<int>(k+1,-1));
        return f(0,k,events,n,t);
    }
};