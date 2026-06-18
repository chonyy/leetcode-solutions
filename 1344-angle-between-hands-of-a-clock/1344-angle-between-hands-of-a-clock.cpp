class Solution {
public:
    double angleClock(int hour, int minutes) {
        int minuteAngle = minutes * 6;
        double hourAngle = (hour % 12) * 30 + (double)minutes / 60 * 30;

        return min(abs(minuteAngle - hourAngle), 360 - abs(minuteAngle - hourAngle));
    }
};