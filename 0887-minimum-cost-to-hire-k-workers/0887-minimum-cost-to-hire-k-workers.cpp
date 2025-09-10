class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=quality.size();
        vector<pair<double,int>>pairs;
        for(int i=0;i<n;i++){
            double r=(double)wage[i]/quality[i];
            pairs.push_back({r,quality[i]}); 
        }
        sort(pairs.begin(),pairs.end());
        double res=INT_MAX;
        int quality_sum=0;
        priority_queue<int>pq;
        for(int i=0;i<k;i++){
            pq.push(pairs[i].second);
            quality_sum+=pairs[i].second;
        }
        res=quality_sum*pairs[k-1].first;
        for(int i=k;i<n;i++){
           pq.push(pairs[i].second);
           quality_sum+=pairs[i].second;
           quality_sum-=pq.top();
           pq.pop();
           res=min(res,(double)quality_sum*pairs[i].first);
          } 
        return res;
    }
};