class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& OI, int FS, int FE) {
        int n=OI.size();
        // merge
        sort(OI.begin(),OI.end());
        vector<vector<int>>merge;
         int prev_st=OI[0][0];
         int prev_end=OI[0][1];
         for(int i=1;i<n;i++){
            if(OI[i][0]<=prev_end+1) prev_end=max(prev_end,OI[i][1]);
            else{
                merge.push_back({prev_st,prev_end});
                prev_st=OI[i][0];
                prev_end=OI[i][1];
            }
         }
        merge.push_back({prev_st,prev_end});
       // FS and FE ka Tandav
       int m=merge.size();
       for(int i=0;i<m;i++){
          if(merge[i][0]<FS && merge[i][1]>FE){
            merge.push_back({FE+1,merge[i][1]});
            merge[i][1]=FS-1;
          }
          if(merge[i][0]>=FS && merge[i][1]<=FE){
            merge[i][0]=0;
            merge[i][1]=0;
          }
          if(merge[i][0]<FS && merge[i][1]>=FS) merge[i][1]=FS-1;
          if(merge[i][0]<=FE && merge[i][1]>FE) merge[i][0]=FE+1;
       }
       //Remove interval--> {0,0}
       sort(merge.begin(),merge.end());
       vector<vector<int>>res;
       for(int i=0;i<merge.size();i++){
        if(merge[i][0]==0 && merge[i][1]==0) continue;
        res.push_back(merge[i]); 
       }
       return res;
    }
};