class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int>freeTime;
         freeTime.push_back(startTime[0]-0);
        for(int i=1;i<n;i++){
            freeTime.push_back(startTime[i]-endTime[i-1]);
        }
        freeTime.push_back(eventTime-endTime[n-1]);
       for(auto &x:freeTime) cout<<x;
        int gap=0,max_gap=0;
        int i=0;
        for(int j=0;j<freeTime.size();j++){
            gap+=freeTime[j];
            while(j-i+1>=k+1){
                max_gap=max(max_gap,gap);
                gap-=freeTime[i];
                i++;
            }
        }
        return max_gap;
    }
};