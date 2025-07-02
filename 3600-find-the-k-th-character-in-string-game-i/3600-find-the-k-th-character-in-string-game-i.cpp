class Solution {
public:
    unordered_map<int, string> t;

    string solve(int pow) {
        if (pow == 1) return "a";
        if (t.count(pow)) return t[pow];

        string left = solve(pow / 2);
        string right = "";
        for (char ch : left) {
            right += 'a' + (ch - 'a' + 1) % 26;
        }

        return t[pow] = left + right;
    }

    char kthCharacter(int k) {
        int pow = 512;  // should be high enough to cover k
        string res = solve(pow);
        return res[k - 1];
    }
};
