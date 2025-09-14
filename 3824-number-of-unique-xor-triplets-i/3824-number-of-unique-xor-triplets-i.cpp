class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<int> basis;
        for (int x : nums) {
            for (int b : basis) {
                x = min(x, x ^ b);
            }
            if (x) basis.push_back(x);
        }
        int d = basis.size();
        
        // Step 2: Apply rule
        if (n >= d + 3) {
            // All XOR values achievable
            return 1 << d;
        } else {
            // Small case -> brute force
            unordered_set<int> st;
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    for (int k = j; k < n; k++) {
                        st.insert(nums[i] ^ nums[j] ^ nums[k]);
                    }
                }
            }
            return st.size();
        }
    }
};