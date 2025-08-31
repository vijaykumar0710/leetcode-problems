class Solution {
public:
const int M=1e9+7;
    int countSubMultisets(vector<int>& arr, int L, int R) {
     int n = arr.size();
        sort(arr.begin(), arr.end());

        // Compress duplicates
        vector<pair<int,int>> vals; // {value, frequency}
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && arr[j] == arr[i]) j++;
            vals.push_back({arr[i], j - i});
            i = j;
        }

        vector<int> dp(R+1, 0);
        dp[0] = 1; // base case: 1 way to make sum 0

        for (auto [val, freq] : vals) {
            vector<int> newdp = dp;
            for (int sum = 0; sum <= R; sum++) {
                if (dp[sum] == 0) continue;
                for (int k = 1; k <= freq && sum + k*val <= R; k++) {
                    newdp[sum + k*val] =(newdp[sum + k*val]+dp[sum])%M;
                }
            }
            dp.swap(newdp);
        }
        long long ans = 0;
        for (int s = L; s <= R; s++) ans =(ans+dp[s])%M;
        return ans;
    }
};