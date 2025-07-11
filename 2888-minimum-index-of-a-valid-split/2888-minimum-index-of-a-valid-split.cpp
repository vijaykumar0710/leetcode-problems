class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, majority_ele = -1;
        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                majority_ele = nums[i];
                cnt = 1;
            } else if (nums[i] == majority_ele) {
                cnt++;
            } else {
                cnt--;
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == majority_ele)
                count++;
        }
        int freq = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == majority_ele)
                freq++;
            int size = i + 1;
            int rem_size = n - size;
            int rem_freq = count - freq;
            if (size < 2 * freq && rem_size < 2 * rem_freq)
                return i;
        }
        return -1;
    }
};