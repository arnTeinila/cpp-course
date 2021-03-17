#include <iostream>
#include <iomanip>
#include "Time.h"

using namespace std;

void Time::read(const char* s) {
        cout << s << " ";
        cin >> hour >> min;
}

bool Time::lessThan(const Time& x) const { 
        int time_1;
        int time_2;

        time_1 = (hour*60 + min);
        time_2 = (x.hour*60 + x.min);

        if(time_1 > time_2){
                return 1;
        }else{
                return 0;
        }

}

Time Time::subtract(const Time& x) const { 
        Time duration;
        
        duration.hour = x.hour - hour;
        duration.min = x.min - min;
        if(duration.min < 0){
                duration.min += 60;
        }
                        
        return duration;        
}

void Time::display() const { 
       cout << setw(2) << setfill('0') << hour << ":" 
        << setw(2) << setfill('0') <<min; 
        
}

bool Time::operator < (const Time& x) const { 
        int time_1;
        int time_2;

        time_1 = (hour*60 + min);
        time_2 = (x.hour*60 + x.min);

        if(time_1 > time_2){
                return 1;
        }else{
                return 0;
        }

}
