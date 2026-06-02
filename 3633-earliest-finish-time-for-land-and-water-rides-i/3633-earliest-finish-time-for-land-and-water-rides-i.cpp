class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int m=ls.size(),n=ws.size();
        vector<pair<int,int>>lt,wt;
        for(int i=0;i<m;i++) lt.push_back({ls[i],ls[i]+ld[i]});
        for(int i=0;i<n;i++) wt.push_back({ws[i],ws[i]+wd[i]});
        sort(lt.begin(),lt.end(),[](auto &a,auto &b){
            if(a.second==b.second) return a.first<b.first;
            return a.second<b.second;
        });
        sort(wt.begin(),wt.end(),[](auto &a,auto &b){
            if(a.second==b.second) return a.first<b.first;
            return a.second<b.second;
        });
        if(lt[0].second<wt[0].first) return wt[0].second;
        else if(wt[0].second<lt[0].first) return lt[0].second;
        return min(wt[0].second+lt[0].second-lt[0].first,lt[0].second+wt[0].second-wt[0].first);
    } 
};