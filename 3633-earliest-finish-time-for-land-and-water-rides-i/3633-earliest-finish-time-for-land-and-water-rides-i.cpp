class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int m=ls.size(),n=ws.size();
        int res=INT_MAX;
        for(int i=0;i<m;i++){
            int t=ls[i]+ld[i];
            for(int j=0;j<n;j++){
                if(ws[j]<=t) res=min(res,t+wd[j]);
                else res=min(res,ws[j]+wd[j]);
            }
        }
        for(int i=0;i<n;i++){
            int t=ws[i]+wd[i];
            for(int j=0;j<m;j++){
                if(ls[j]<=t) res=min(res,t+ld[j]);
                else res=min(res,ls[j]+ld[j]);
            }
        }
        return res;
    }
};