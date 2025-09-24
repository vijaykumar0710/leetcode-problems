class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> pref(m, vector<int>(n, 0));
        vector<int> res;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = matrix[i][j];
                if (i > 0) val ^= pref[i-1][j];
                if (j > 0) val ^= pref[i][j-1];
                if (i > 0 && j > 0) val ^= pref[i-1][j-1];
                pref[i][j] = val;
                res.push_back(val);
            }
        }

        nth_element(res.begin(), res.begin() + (k-1), res.end(), greater<int>());
        return res[k-1];
    }
};
