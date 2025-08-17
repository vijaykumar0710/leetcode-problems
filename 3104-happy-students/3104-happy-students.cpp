class Solution {
public:
    int countWays(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int count = 0;

    // Case 1: The class teacher selects no student.
    // In this case, the number of selected students is 0.
    // For every student to be happy, they must not be selected, and
    // the number of selected students (0) must be strictly less than nums[i].
    // This means 0 < nums[i] for all i. Since the array is sorted, we only
    // need to check the first element. If nums[0] > 0, then all elements
    // are greater than 0.
    if (nums[0] > 0) {
        count++;
    }

    // Iterate through all possible group sizes from 1 to n.
    // Let 'k' be the number of selected students.
    for (int k = 1; k <= n; ++k) {
        // Condition for 'k' students to be selected and everyone to be happy.
        // All 'k' selected students (at indices 0 to k-1) must satisfy k > nums[i].
        // Since the array is sorted, we only need to check the last selected student.
        // If k > nums[k-1], then k will be greater than all nums[i] for i < k.
        
        // All 'n-k' non-selected students (at indices k to n-1) must satisfy k < nums[i].
        // Since the array is sorted, we only need to check the first non-selected student.
        // If k < nums[k], then k will be less than all nums[i] for i >= k.
        
        // Check both conditions.
        // The first part of the condition handles k > nums[k-1].
        // The second part handles k < nums[k]. We need to be careful with the
        // edge case where k = n.
        bool first_cond = (k > nums[k - 1]);
        bool second_cond = (k < n && k < nums[k]) || (k == n);

        if (first_cond && second_cond) {
            count++;
        }
    }
    return count;
    }
};