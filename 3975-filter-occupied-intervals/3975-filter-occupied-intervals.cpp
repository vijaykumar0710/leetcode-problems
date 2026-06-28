class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& OI, int freeStart, int freeEnd) {
        int n=OI.size();
        vector<vector<int>>res;
        sort(OI.begin(),OI.end());
        int prev_st=OI[0][0];
        int prev_end=OI[0][1];
        for(int i=1;i<n;i++){
           if(OI[i][0]<=prev_end+1){
            prev_end=max(prev_end,OI[i][1]);
           }else{
            res.push_back({prev_st,prev_end});
            prev_st=OI[i][0];
            prev_end=OI[i][1];
           }
        }
        res.push_back({prev_st,prev_end});
        int m=res.size();
        for(int i=0;i<m;i++){
           if(res[i][0]<freeStart && res[i][1]>freeEnd){
              res.push_back({freeEnd+1,res[i][1]});
              res[i][1]=freeStart-1;
           }
           if(res[i][0]>=freeStart && res[i][1]<=freeEnd){
            res[i][0]=0;
            res[i][1]=0;
           }
           if(res[i][0]<freeStart && res[i][1]>=freeStart) res[i][1]=freeStart-1;
           if(res[i][0]<=freeEnd && res[i][1]>freeEnd) res[i][0]=freeEnd+1;
        }
        sort(res.begin(),res.end());
        vector<vector<int>>ans;
        for(int i=0;i<res.size();i++){
            if(res[i][0]==0 && res[i][1]==0) continue;
            ans.push_back(res[i]);
        }
        return ans;
    }
};