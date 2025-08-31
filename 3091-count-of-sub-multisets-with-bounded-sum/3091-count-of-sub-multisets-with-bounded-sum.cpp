class Solution {
public:
const int M=1e9+7;
    int countSubMultisets(vector<int>& arr, int L, int R) {
     int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<pair<int,int>> vals; 
        int cnt=1;
        int i=1;
        for (; i < n;i++) {
            if(arr[i]==arr[i-1]) cnt++;
            else{
                vals.push_back({arr[i-1],cnt});
                cnt=1;
            }
        }
        vals.push_back({arr[i-1],cnt});

        vector<int> dp(R+1, 0);
        dp[0] = 1;
        for (auto [val, freq] : vals) {
            vector<int> newdp = dp;
            for (int sum = 0; sum <= R; sum++) {
                if (dp[sum] == 0) continue;
                for (int k = 1; k <= freq; k++) {
                    if(sum + k*val <= R)
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