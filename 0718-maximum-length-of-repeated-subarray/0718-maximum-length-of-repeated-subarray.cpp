class Solution {
public:
    struct RollingHash {
        vector<long long> prefix_hash, power;
        long long base = 131;
        long long mod = 1e9 + 7;
        RollingHash(const vector<int>& nums) {
            int n = nums.size();
            prefix_hash.assign(n + 1, 0);
            power.assign(n + 1, 1);
            for (int i = 0; i < n; i++) {
                prefix_hash[i + 1] = (prefix_hash[i] * base + nums[i]) % mod;
                power[i + 1] = (power[i] * base) % mod;
            }
        }
        long long get_hash(int l, int r) {
            return (prefix_hash[r + 1] + mod -
                    (prefix_hash[l] * power[r - l + 1]) % mod) %
                   mod;
        }
    };
    bool isPossible( int mid, RollingHash& rh1,
                    RollingHash& rh2,int n1,int n2) {
        unordered_set<long long> seen;

        for (int i = 0; i <= n1 - mid; i++) {
            long long h1 = rh1.get_hash(i, i + mid - 1);
            seen.insert(h1);
        }

        for (int i = 0; i <= n2 - mid; i++) {
            long long h2 = rh2.get_hash(i, i + mid - 1);
            if (seen.count(h2))
                return true;
        }
        return false;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
       int n1 = nums1.size();
       int n2 = nums2.size();
        RollingHash rh1(nums1);
        RollingHash rh2(nums2);
        int l = 1, r =min(n1,n2);
        int res = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isPossible(mid, rh1, rh2,n1,n2)) {
                res = max(res, mid);
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return res;
    }
};