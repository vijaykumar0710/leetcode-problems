class Solution {
public:
    char getChar(int i, long long k, vector<int>& operations, vector<long long>& length) {
        if (i == 0) return 'a';  // Initially "a"

        long long prevLen = length[i - 1];

        if (k <= prevLen) {
            return getChar(i - 1, k, operations, length);
        }

        if (operations[i - 1] == 0) {
            // Duplicate: word = word + word
            return getChar(i - 1, k - prevLen, operations, length);
        } else {
            // Increment: word = word + inc(word)
            char ch = getChar(i - 1, k - prevLen, operations, length);
            return 'a' + (ch - 'a' + 1) % 26;
        }
    }

    char kthCharacter(long long k, vector<int>& operations) {
        int n = operations.size();
        vector<long long> length(n + 1);
        length[0] = 1;  // "a"

        for (int i = 1; i <= n; i++) {
            if (operations[i - 1] == 0 || operations[i - 1] == 1) {
                // Both operations double the string size
                length[i] = min(length[i - 1] * 2, k);
            }
        }

        return getChar(n, k, operations, length);
    }
};
