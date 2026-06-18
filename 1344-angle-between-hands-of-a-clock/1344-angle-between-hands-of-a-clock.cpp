class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle_diff=abs((double)30*hour-5.5*minutes);
        return min(angle_diff,360-angle_diff);
    }
};