class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>t(n);
        t[0]=nums[0];
        int maxi=t[0];
        priority_queue<pair<int,int>>pq;
        pq.push({t[0],0});
        for(int i=1;i<n;i++){
          while(!pq.empty() && i-(-pq.top().second)>k) pq.pop();
          t[i]=nums[i]+max(0,pq.top().first);
          maxi=max(maxi,t[i]);
          pq.push({t[i],-i});
        }
        return maxi;
    }
};