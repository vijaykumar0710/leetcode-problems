class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> pow2(n, 1);

        // Precompute powers of 2 modulo MOD
        for (int i = 1; i < n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        int i = 0, j = n - 1;
        int res = 0;

        while (i <= j) {
            if (nums[i] + nums[j] <= target) {
                res = (res + pow2[j - i]) % MOD;
                i++;
            } else {
                j--;
            }
        }
        return res;
    }
};
