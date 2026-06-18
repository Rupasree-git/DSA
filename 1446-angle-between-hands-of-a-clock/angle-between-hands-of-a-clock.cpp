class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minutes1=0.0,extra_hr_rot=0.0,ans1=0.0,ans2=0.0;
        if(hour==12)
            hour=0*30;
        else
            hour=hour*30;
        minutes1=minutes*6;
        extra_hr_rot=(minutes/60.0)*30;
        ans1=abs(minutes1-hour-extra_hr_rot);
        ans2=abs(360-ans1);
        return min(ans1,ans2);
    }
};