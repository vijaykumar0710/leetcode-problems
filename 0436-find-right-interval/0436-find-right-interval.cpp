class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int>res;
        multimap<int,int>mp;
        vector<int>end;
        for(int i=0;i<n;i++){ 
            end.push_back(intervals[i][1]);
            mp.insert({intervals[i][0],i});
        }
        for(int i=0;i<n;i++){
            auto it=mp.lower_bound(end[i]);
            if(it!=mp.end()) res.push_back(it->second);
            else res.push_back(-1);
        }
        return res; 
    }
};