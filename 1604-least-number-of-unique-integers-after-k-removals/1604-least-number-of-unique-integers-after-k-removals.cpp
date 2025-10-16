class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto x:arr) mp[x]++;
        for(auto [x,f]:mp) pq.push(f);
        while(k-- && !pq.empty()){
           int f=pq.top();
           pq.pop();
           f--;
           if(f!=0)pq.push(f);
        }
        return pq.size();
    }
};