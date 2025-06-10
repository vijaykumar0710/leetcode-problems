class Solution {
public:
    bool f(vector<int>& nums, long long target, long long sum, int mask, int k, int n, vector<int>& dp) {
        if (k == 0) return true;
        if (dp[mask] != -1) return dp[mask];
        
        for (int i = 0; i < n; i++) {
            // if element i is unused and adding it doesn't exceed target
            if (!(mask & (1 << i)) && sum + nums[i] <= target) {
                long long newSum = sum + nums[i];
                int newMask = mask | (1 << i);
                
                if (newSum == target) {
                    // start a new subset
                    if (f(nums, target, 0, newMask, k - 1, n, dp))
                        return dp[mask] = 1;
                } else {
                    if (f(nums, target, newSum, newMask, k, n, dp))
                        return dp[mask] = 1;
                }
            }
        }
        return dp[mask] = 0;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        if (total % k != 0) return false;
        
        long long target = total / k;
        int mask = 0;
        vector<int> dp(1 << n, -1); // memoize by mask only

        return f(nums, target, 0, mask, k, n, dp);
    }
};
