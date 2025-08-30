typedef long long ll;
const int M = 1337;

class Solution {
public:
    ll generatePalindrome(ll left) {
        string s = to_string(left);
        string t = s;
        reverse(t.begin(), t.end());
        return stoll(s + t); 
    }

    int largestPalindrome(int n) {
        if (n == 1) return 9; 
        
        ll upper = pow(10, n) - 1;
        ll lower = pow(10, n - 1);

        for (ll left = upper; left >= lower; left--) {
            ll palindrome = generatePalindrome(left);
            for (ll y = upper; y * y >= palindrome; y--) {
                if (palindrome % y == 0) {
                    ll other = palindrome / y;
                    if (other >= lower && other <= upper) {
                        return palindrome % M;
                    }
                }
            }
        }
        return 0;
    }
};