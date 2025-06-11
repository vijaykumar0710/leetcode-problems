class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false; // odd sum can't be divided
        int target = sum / 2;
        bitset<10001> dp; // assuming target <= 10000
        dp[0] = 1;
        for (int num : nums) {
            dp |= (dp << num);
        }

        return dp[target];
    }
};
