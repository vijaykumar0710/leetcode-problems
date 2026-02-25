class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n=arr.size();
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++){
            p.push_back({__builtin_popcount(arr[i]),arr[i]});
        }
        sort(p.begin(),p.end());
        for(int i=0;i<n;i++) arr[i]=p[i].second;
        return arr;
    }
};