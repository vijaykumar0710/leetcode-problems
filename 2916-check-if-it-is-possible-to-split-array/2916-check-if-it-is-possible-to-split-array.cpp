class Solution {
public:
    bool f(int l, int r, vector<int>& nums, vector<int>& prefix_sum, int m,vector<vector<int>>&t) {
        if (r == l) return true;

      if(t[l][r]!=-1) return t[l][r];
        int sum = prefix_sum[r + 1] - prefix_sum[l];
        if (sum < m) return false;

        for (int k = l; k < r; k++) {
            if (f(l, k, nums, prefix_sum, m,t) && f(k + 1, r, nums, prefix_sum, m,t)) {
                return t[l][r]=true;
            }
        }
        return t[l][r]=false;
    }
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if(n<=2) return true;
        vector<int> prefix_sum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }
        vector<vector<int>>t(n+1,vector<int>(n+1,-1));
        return f(0, n - 1, nums, prefix_sum, m,t);
    }
};
