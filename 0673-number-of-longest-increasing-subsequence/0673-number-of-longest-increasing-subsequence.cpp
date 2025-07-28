class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int max_len = 1;
        vector<int> t(n, 1);
        vector<int> cnt(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    if (t[i] < t[j] + 1) {
                        t[i] = t[j] + 1;
                        max_len = max(max_len, t[i]);
                        cnt[i] = cnt[j];
                    } else if (t[i] == t[j] + 1) {
                        cnt[i] += cnt[j];
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (t[i] == max_len)
                res += cnt[i];
        }
        return res;
    }
};