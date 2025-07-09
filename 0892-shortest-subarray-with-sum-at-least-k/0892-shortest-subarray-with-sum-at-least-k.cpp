class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix_sum(n+1,0);
        for (int i = 0; i < n; i++) {
            prefix_sum[i+1] = nums[i] + prefix_sum[i];
        }

        int len = INT_MAX;
        deque<int> dq;

        for (int i = 0; i <= n; i++) {
            while (!dq.empty() && prefix_sum[i] - prefix_sum[dq.front()] >= k) {
                len = min(len, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && prefix_sum[dq.back()] >= prefix_sum[i])
                dq.pop_back();
            dq.push_back(i);
        }

        return len == INT_MAX ? -1 : len;
    }
};