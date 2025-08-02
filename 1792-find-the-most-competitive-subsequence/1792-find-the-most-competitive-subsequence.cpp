class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()>nums[i] && st.size()+(n-i-1)>=k) st.pop();
            st.push(nums[i]);
        }
        vector<int>res;
       while(st.size()>k) st.pop();
       while(!st.empty()){
          res.push_back(st.top());
          st.pop();
       }
       reverse(res.begin(),res.end());
       return res;
    }
};