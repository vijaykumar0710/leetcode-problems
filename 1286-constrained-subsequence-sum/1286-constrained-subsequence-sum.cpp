class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>t(n);
        deque<int>dq;
        dq.push_back(0);
        t[0]=nums[0];
        int maxi=t[0];
        for(int i=1;i<n;i++){
           while(!dq.empty() && i-dq.front()>k) dq.pop_front();
           t[i]=nums[i]+max(0,t[dq.front()]);
           maxi=max(maxi,t[i]);
           while(!dq.empty() && t[dq.back()]<t[i]) dq.pop_back();
           dq.push_back(i);
        }
        return maxi;
    }
};