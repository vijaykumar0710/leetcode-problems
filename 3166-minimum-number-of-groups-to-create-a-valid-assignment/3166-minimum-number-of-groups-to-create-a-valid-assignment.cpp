class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
         unordered_map<int, int> frequency;
        for (int num : nums) {
            frequency[num]++;
        }
         int minFrequency = INT_MAX;
        for (auto& [value, count] : frequency) {
            minFrequency = min(minFrequency, count);
        }
        for (int groupSize = minFrequency; groupSize >= 1; --groupSize) {
            int totalGroups = 0;
            bool isValidAssignment = true;
            for (auto& [value, count] : frequency) {
                if (count / groupSize < count % groupSize) {
                    isValidAssignment = false;
                    break;
                }
                totalGroups += (count + groupSize) / (groupSize + 1);
            }
            if (isValidAssignment) {
                return totalGroups;
            }
        }
        return 0;
    }
};