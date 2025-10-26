class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n = capacity.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + capacity[i];
        unordered_map<long long, unordered_map<long long, int>> mp;
        long long ans = 0;
        for (int r = 0; r < n; ++r) {
            if (r - 2 >= 0) {
                int l = r - 2;
                long long valL = capacity[l];
                long long key = prefix[l + 1] + valL;
                mp[valL][key] += 1;
            }
            long long valR = capacity[r];
               if (mp.count(valR)) {
                auto it = mp[valR].find(prefix[r]);
                if (it != mp[valR].end()) ans += it->second;
            }
        }
        return ans;
    }
};
