class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
           return a[1]<b[1];
        });
        int n=intervals.size();
        int start=intervals[0][0];
        int end=intervals[0][1];
        int res=0;
        for(int i=1;i<n;i++){
            int curr_start=intervals[i][0];
            int curr_end=intervals[i][1];
            if(end>curr_start) res++;
            else{
                start=curr_start;
                end=curr_end;
            }
        }
        return res;
    }
};