class Solution {
public:
vector<pair<int,int>>intervals;
void cal_interval(vector<int>&arr,int target){
int n=arr.size(),sum=0,i=0;
intervals.clear(); 
for(int j=0;j<n;j++){
    sum+=arr[j];
    while(sum>target && i<=j){ sum-=arr[i]; i++; }
   if(sum==target) intervals.push_back({i,j});
   }
}
int cal_minLen(vector<pair<int,int>>&intervals){
    int n=intervals.size();
    if (n < 2) return -1;
    vector<pair<int,int>>start=intervals;
    sort(start.begin(),start.end());
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int res=INT_MAX;
    int min_len=INT_MAX;
    for(int j=0;j<n;j++){
        while(!pq.empty() && pq.top().first<start[j].first){
            min_len=min(min_len,pq.top().second);
            pq.pop();
        }
        if(min_len!=INT_MAX){
            res=min(res,min_len+start[j].second-start[j].first+1);
        }
         pq.push({start[j].second,start[j].second-start[j].first+1});
    }
    return res==INT_MAX?-1:res;
}
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        cal_interval(arr,target);
        return  cal_minLen(intervals);
    }
};