class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n=intervals.size(),m=queries.size();
        vector<pair<int,int>>sortQueires;
        vector<int>res(m);
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<m;i++)sortQueires.push_back({queries[i],i}); 
        sort(sortQueires.begin(),sortQueires.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int j=0;
        for(int i=0;i<m;i++){
            int q=sortQueires[i].first;
            while(j<n && intervals[j][0]<=q){
                int len=intervals[j][1]-intervals[j][0]+1;
                pq.push({len,intervals[j][1]});
                j++;
            }
            while(!pq.empty()&&pq.top().second<q) pq.pop();
            res[sortQueires[i].second]=pq.empty()?-1:pq.top().first;
        }
        return res;
    }
};