class Solution {
public:
    double epsilon = 0.1;
    bool solve(vector<double>& nums) {
        if (nums.size() == 1) {
            return abs(24 - nums[0]) <= epsilon;
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j)
                    continue;
                vector<double> vec;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j)
                        vec.push_back(nums[k]);
                }
                double a = nums[i];
                double b = nums[j];
                vector<double> temp = {a + b, a - b, b - a, a * b};
                if (abs(a) > 0.0)
                    temp.push_back(b / a);
                if (abs(b) > 0.0)
                    temp.push_back(a / b);
                for (double val : temp) {
                    vec.push_back(val);     // Do
                    if (solve(vec) == true) // Explore
                        return true;
                    vec.pop_back(); // Undo
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (auto& card : cards)
            nums.push_back(1.0 * card);
        return solve(nums);
    }
};