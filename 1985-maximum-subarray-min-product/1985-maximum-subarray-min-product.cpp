class Solution {
public:
const int M=1e9+7;
    int maxSumMinProduct(vector<int>& nums) {
        int n=nums.size();

        vector<long long>prefix_sum(n);
        vector<int>left_idx(n),right_idx(n);
        stack<int>st;

        prefix_sum[0]=nums[0];
        for(int i=1;i<n;i++){
          prefix_sum[i]=prefix_sum[i-1]+nums[i];
        }

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
            left_idx[i]=st.empty()?-1:st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
            right_idx[i]=st.empty()?n:st.top();
            st.push(i);
        }

        long long res=0;
        for(int i=0;i<n;i++){
          int left=left_idx[i];
          int right=right_idx[i];
          long long total=prefix_sum[right-1];
          if(left>=0) total-=prefix_sum[left];
          long long pro=nums[i]*total;
          res=max(res,pro);
        }

        return res%M;
    }
};