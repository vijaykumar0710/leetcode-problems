class Solution {
public:
    int lastRemaining(int n) {
        int head = 1, steps = 1;
        bool left = true;
        while (n > 1) {
            if (left || n % 2 == 1) {
                head += steps;
            }
            n /= 2;
            steps *= 2;
            left = !left;
        }
        return head;
    }
};