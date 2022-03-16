class Solution {
public:
    double angleClock(int hour, int minutes) {
        double a = minutes*6;
        double b = (hour*30 + minutes*0.5);
        
        return min(abs(a-b),360-abs(a-b));
    }
};