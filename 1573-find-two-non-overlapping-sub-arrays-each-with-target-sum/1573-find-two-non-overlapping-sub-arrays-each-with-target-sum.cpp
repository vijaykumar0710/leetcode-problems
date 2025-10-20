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
    vector<pair<int,int>>end=start;
    sort(end.begin(),end.end(),[](auto &a,auto &b){
       return a.second<b.second;
    });
    int res=INT_MAX;
    int min_len=INT_MAX,i=0;
    for(int j=0;j<n;j++){
        while(i<n && end[i].second<start[j].first){
            min_len=min(min_len,end[i].second-end[i].first+1);
            i++;
        }
        if(min_len!=INT_MAX){
            res=min(res,min_len+start[j].second-start[j].first+1);
        }
    }
    return res==INT_MAX?-1:res;
}
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        cal_interval(arr,target);
        return  cal_minLen(intervals);
    }
};