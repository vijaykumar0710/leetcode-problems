class Solution {
public:
int binarySearch(int i,int endTime,vector<vector<int>>& events){
    int l=i,r=events.size()-1;
    int idx=events.size();
    while(l<=r){
        int mid=l+(r-l)/2;
        if(events[mid][0]>=endTime){
            idx=mid;
            r=mid-1;
        }else l=mid+1;
    }
    return idx;
}

int f(int i,vector<vector<int>>& events,int n,vector<int>&t){
    if(i==n) return 0;

    if(t[i]!=-1) return t[i];

    int nextIdx=binarySearch(i+1,events[i][1],events);
    int take=events[i][2]+f(nextIdx,events,n,t);

    int skip=f(i+1,events,n,t);
    return t[i]=max(take,skip);
}
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>events;
        for(int i=0;i<profit.size();i++){
            events.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(events.begin(),events.end());
        int n=events.size();
        vector<int>t(n+1,-1);
        return f(0,events,n,t);
    }
};