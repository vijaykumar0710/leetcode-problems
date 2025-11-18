class Solution {
public:
const int M=1e9+7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n=nums.size();
        vector<int>diff_arr(n+1,0);
        for(auto &req:requests){
            int l=req[0],r=req[1];
            diff_arr[l]++;
            diff_arr[r+1]--;
        }
        for(int i=1;i<=n;i++) diff_arr[i]+=diff_arr[i-1];
        priority_queue<int>pq(nums.begin(),nums.end());
        sort(diff_arr.rbegin(),diff_arr.rend());
        long long res=0ll;
        for(int i=0;i<=n;i++){
            res=(res+1ll*pq.top()*diff_arr[i])%M;
            pq.pop();
        }
         return res;
    }
};