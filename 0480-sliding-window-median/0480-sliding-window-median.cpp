#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        ordered_set<pair<int, int>> ost;
        vector<double> res;
        int i = 0;
        for (int j = 0; j < n; j++) {
            ost.insert({nums[j], j});
            if (j - i + 1 == k) {
                int target_rank1 = (k - 1) / 2;
                int target_rank2 = k / 2;
                auto it1 = ost.find_by_order(target_rank1);
                auto it2 = ost.find_by_order(target_rank2); 
                double x = ((double)it1->first + it2->first) / 2;
                if (k % 2 == 0) res.push_back(x);
                else res.push_back(it1->first);
                ost.erase({nums[i], i});
                i++;
            }
        }
        return res;
    }
};