class Solution {
public:
    struct RollingHash {
        typedef long long ll;
        vector<ll> prefix_hash, power;
     ll mod = 1e9 + 7;
     ll base = 131;
        RollingHash(const string &s) {
            int n = s.size();
            prefix_hash.assign(n + 1, 0);
            power.assign(n + 1, 1);

            for (int i = 0; i < n; i++) {
                prefix_hash[i + 1] = (prefix_hash[i] * base + s[i]) % mod;
                power[i + 1] = (power[i] * base) % mod;
            }
        }

        ll get_hash(int l, int r) {
            return (prefix_hash[r + 1]+mod - prefix_hash[l] * power[r - l + 1] % mod) % mod;
        }
    };

    struct ReverseRollingHash {
        typedef long long ll;
        vector<ll> suffix_hash, power;
     ll mod = 1e9 + 7;
     ll base = 131;
        ReverseRollingHash(const string &s) {
            int n = s.size();
            suffix_hash.assign(n + 1, 0);
            power.assign(n + 1, 1);

            for (int i = n - 1; i >= 0; i--) {
                suffix_hash[i] = (suffix_hash[i + 1] * base + s[i]) % mod;
            }

            for (int i = 0; i < n; i++) {
                power[i+1] = (power[i] * base) % mod;
            }
        }

        ll get_hash(int l, int r) {
            // reverse of s[l..r] = s[r]s[r-1]...s[l]
            // suffix_hash[l] contains hash of s[l..]
            return (suffix_hash[l]+mod - suffix_hash[r + 1] * power[r - l + 1] % mod) % mod;
        }
    };

    string shortestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        RollingHash forward(s);
        ReverseRollingHash backward(s);

        int best = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (forward.get_hash(0, i) == backward.get_hash(0, i)) {
                best = i;  // longest palindromic prefix
                break;
            }
        }

        string suffix = s.substr(best + 1);
        reverse(suffix.begin(), suffix.end());
        return suffix + s;
    }
};
