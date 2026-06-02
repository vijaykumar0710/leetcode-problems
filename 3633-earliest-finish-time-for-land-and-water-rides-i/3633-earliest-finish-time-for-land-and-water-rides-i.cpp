class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int m=ls.size(),n=ws.size();
       int mini=INT_MAX;
       for(int i=0;i<m;i++){
        int d1=ls[i]+ld[i];
        for(int j=0;j<n;j++){
            if(ws[j]<=d1) mini=min(mini,d1+wd[j]);
            else mini=min(mini,d1+wd[j]+ws[j]-d1);
        }
       }
       for(int i=0;i<n;i++){
        int d1=ws[i]+wd[i];
        for(int j=0;j<m;j++){
            if(ls[j]<=d1) mini=min(mini,d1+ld[j]);
            else mini=min(mini,d1+ld[j]+ls[j]-d1);
        }
       }
       return mini;
    } 
};