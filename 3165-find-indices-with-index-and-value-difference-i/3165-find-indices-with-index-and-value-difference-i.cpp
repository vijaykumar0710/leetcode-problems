class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        multiset<pair<int,int>> st;
        for (int j = 0; j < n; j++) {
            if (j >= indexDifference) {
                st.insert({nums[j - indexDifference], j - indexDifference});
            }
            if (!st.empty()) {
                auto it1 = st.upper_bound({nums[j] - valueDifference, INT_MAX});
                if (it1 != st.begin()) {
                    --it1;
                    if (abs(nums[j] - it1->first) >= valueDifference) {
                        return {it1->second, j};
                    }
                }
                auto it2 = st.lower_bound({nums[j] + valueDifference, INT_MIN});
                if (it2 != st.end()) {
                    if (abs(nums[j] - it2->first) >= valueDifference) {
                        return {it2->second, j};
                    }
                }
            }
        }
        return {-1, -1};
    }
};