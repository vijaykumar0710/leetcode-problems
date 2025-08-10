class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<nums[i]) st.pop();
            st.push(nums[i]);
        }
        return st.size();
    }
};