class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        vector<int> LIS(n, 1);
        int max_LIS = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                bool flag = true;
                for (int k = 0; k < strs.size(); k++) {
                    if (strs[k][j] > strs[k][i]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                    max_LIS = max(max_LIS, LIS[i]);
                }
            }
        }
        return n - max_LIS;
    }
};