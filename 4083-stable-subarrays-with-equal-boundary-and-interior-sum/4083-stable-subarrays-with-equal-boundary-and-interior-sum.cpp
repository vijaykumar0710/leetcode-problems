#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n = capacity.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + capacity[i];

        // mp[val][key] = count of l such that (prefix[l+1] + val) == key
        unordered_map<long long, unordered_map<long long, int>> mp;
        long long ans = 0;

        // We will treat r from 0..n-1, but only r >= 2 can contribute.
        // Before processing r, we insert l = r-2 into mp so mp contains only l <= r-2.
        for (int r = 0; r < n; ++r) {
            if (r - 2 >= 0) {
                int l = r - 2;
                long long valL = capacity[l];
                long long key = prefix[l + 1] + valL; // prefix[l+1] + capacity[l]
                mp[valL][key] += 1;
            }

            long long valR = capacity[r];
            // Now mp contains only l <= r-2. Query how many satisfy prefix[r] == prefix[l+1] + val
            if (mp.count(valR)) {
                auto it = mp[valR].find(prefix[r]);
                if (it != mp[valR].end()) ans += it->second;
            }
        }
        return ans;
    }
};
