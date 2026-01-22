class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int minOPs = 0;
    while (true) {
        bool sorted = true;
        int n = nums.size();

        for (int i = 0;i < n - 1;i++) {
            if (nums[i] > nums[i + 1]) {
                sorted = false;
                break;
            }
        }
        if (sorted) break;
        int min_Sum = INT_MAX;
        int min_Index = -1;

        for (int i = 0; i < n - 1;i++) {
            int sum = nums[i] + nums[i + 1];
            if (sum < min_Sum) {
                min_Sum = sum;
                min_Index = i;
            }
        }
        int merged = nums[min_Index] + nums[min_Index + 1];
        nums[min_Index] = merged;
        nums.erase(nums.begin() + min_Index + 1); 

        minOPs++;
    }

    return minOPs;
    }
};