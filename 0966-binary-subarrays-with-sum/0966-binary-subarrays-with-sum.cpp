class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        int i = 0, j=0,sum = 0, count = 0;
        while (j<nums.size()) {
            sum += nums[j];
            while (i <= j && sum > goal) {
                sum -= nums[i];
                i++;
            }
            count += j - i + 1;  // subarrays ending at j
            j++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if (goal < 0) return 0; // No valid subarray can have negative sum
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};
