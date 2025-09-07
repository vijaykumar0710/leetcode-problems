class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>max_reach(n+1,0);
        for(int i=0;i<=n;i++){
            int l=max(0,i-ranges[i]);
            int r=min(n,i+ranges[i]);
            max_reach[l]=max(max_reach[l],r);
        }
        int end=0,curr_end=0,cnt=0;
        for(int i=0;i<=n;i++){
            if(end<i) return -1;
            if(i>curr_end){
            cnt++;
            curr_end=end;
            }
            end=max(end,max_reach[i]);
        }
        return cnt;
    }
};