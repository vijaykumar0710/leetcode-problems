class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        const int MAXB = 31; // max bit index for 2^31
        vector<long long> cnt(MAXB + 1, 0);

        for (int x : nums) {
            int p = __builtin_ctz(x);
            cnt[p]++;
        }

        int ops = 0;
        int missing = -1;

        for (int i = 0; i <= MAXB; i++) {
            if ((target) & (1<<i)) {
                if (cnt[i] > 0) {
                    cnt[i]--;
                } else if (missing == -1) {
                    missing = i;
                }
            }

            if (missing != -1 && cnt[i] > 0) {
                ops += (i - missing);
                cnt[i]--;
                missing = -1;
            }

            if (i < MAXB) { // prevent out-of-bounds
                cnt[i + 1] += cnt[i] / 2;
            }
        }
        return (missing == -1) ? ops : -1;
    }
};
