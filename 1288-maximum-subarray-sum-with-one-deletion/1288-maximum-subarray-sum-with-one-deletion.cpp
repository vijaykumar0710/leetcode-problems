class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> dpNoDel(n), dpDel(n);

        dpNoDel[0] = arr[0];
        dpDel[0] = -1e5;  // can't delete before start

        int ans = arr[0];

        for(int i = 1; i < n; i++) {
            dpNoDel[i] = max(dpNoDel[i-1] + arr[i], arr[i]);
            dpDel[i] = max(dpDel[i-1] + arr[i], dpNoDel[i-1]);
            ans = max({ans, dpNoDel[i], dpDel[i]});
        }

        return ans;
    }
};
