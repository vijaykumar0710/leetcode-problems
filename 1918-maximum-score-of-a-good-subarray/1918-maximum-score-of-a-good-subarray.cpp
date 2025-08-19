class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>left(n),right(n);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
            left[i]=st.empty()?-1:st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
            right[i]=st.empty()?n:st.top();
            st.push(i);
        }
    
        int res=0;
        for(int i=0;i<n;i++){
            int left_idx=left[i];
            int right_idx=right[i];
            if(left_idx+1<=k && right_idx-1>=k){
                int len=right_idx-left_idx-1;
                res=max(res,nums[i]*len);
            }
        }
        return res;
    }
};