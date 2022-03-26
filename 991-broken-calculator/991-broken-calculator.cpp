class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int steps = 0;
        while(target > startValue) {
            if(target % 2) {
                target ++;
            }
            else {
                target /= 2;
            }
            steps ++;
        }
        return steps + startValue - target;
    }
};