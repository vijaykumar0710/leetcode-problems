class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>t(n);
        deque<int>dq;
         t[0]=nums[0];
         dq.push_back(0);
        for(int i=1;i<n;i++){
            while(!dq.empty() && dq.front()<i-k) dq.pop_front();
             t[i]=nums[i]+t[dq.front()];
            while(!dq.empty() && t[dq.back()]<t[i]) dq.pop_back();
            dq.push_back(i);
        }
        return t[n-1];
    }
};