class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 1;
        int i = 0;
        while (i < n-1) {
            if (cnt >= k) {
                while (i+1<n && nums[i] == nums[i + 1]) {
                    nums[i] = INT_MAX;
                    i++;
                }
            }
            if (i+1<n && nums[i] == nums[i + 1])
                cnt++;
            else
                cnt = 1;
         i++;
        }
        sort(nums.begin(),nums.end());
        int cnt1=count(nums.begin(),nums.end(),INT_MAX);
        int sz=n-cnt1;
        nums.resize(sz);
        return nums;
    }
};