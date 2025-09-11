class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int idx, int val) {
        int n = nums.size();
        vector<int> mini(n), maxi(n), minIdx(n), maxIdx(n);
        mini[0] = maxi[0] = nums[0];
        minIdx[0] = maxIdx[0] = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] <= mini[i-1]) {
                mini[i] = nums[i];
                minIdx[i] = i;
            } else {
                mini[i] = mini[i-1];
                minIdx[i] = minIdx[i-1];
            }
            if (nums[i] >= maxi[i-1]) {
                maxi[i] = nums[i];
                maxIdx[i] = i;
            } else {
                maxi[i] = maxi[i-1];
                maxIdx[i] = maxIdx[i-1];
            }
        }
        for (int j = idx; j < n; j++) {
            int i = j - idx;
            if (abs(nums[j] - mini[i]) >= val) return {minIdx[i], j};
            if (abs(nums[j] - maxi[i]) >= val) return {maxIdx[i], j};
        }
        return {-1, -1};
    }
};