//lab 5a
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <cstring>
#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

class Time {
	friend ostream &operator << (ostream &out, Time x);

	private:
                int hours;
                int mins;
        public:
		Time(){
                        hours = 0;
                        mins = 0;
                }
                void read(string prompt);
		bool operator < (Time x);
                Time operator + (Time x);
                Time operator - (Time x);
                //pre increment
                Time& operator ++ ();
                //post increment
                Time operator ++ (int);
		//display time
};

void print(const vector<Time> &v) 
{
	for(auto &t : v) {
		cout << t << endl;
	}
}



int main() {
	Time time1, time2, duration;

	time1.read("Enter time 1");
	time2.read("Enter time 2");
	if (time1<time2) {
		duration = time2 - time1;
		cout << "Starting time was " << time1 << endl;
	} else {
		duration = time1 - time2;
		cout << "Starting time was " << time2 << endl;
	}
	cout << "Duration was " << duration << endl;

	vector<Time> tv(5); 
	for(auto &t : tv) {
		t.read("Enter time:");
	}

	cout << "Times: " << endl;
	print(tv);
	
	Time sum;
	for(auto t : tv) {
		sum = sum + t;
	}
	
	cout << "Sum of times: " << sum << endl;
	
	cout << "Post-increment: " << endl;
	print(tv);
	for(auto &t : tv) {
		cout << t++ << endl;
	}
	
	print(tv);

	cout << "Pre-increment: " << endl;
	for(auto &t : tv) {
		cout << ++t << endl;
	}

	sort(tv.begin(), tv.end());

	cout << "Sorted times: " << endl;
	print(tv);

	return 0;
}

void Time::read(string prompt) {   
        cout << prompt << endl;
        cout << "Hours: " << endl;
        cin >> hours;
        cout << "Minutes: " << endl;
        cin >> mins;

}

bool Time::operator < (Time x) { 
        int time_1;
        int time_2;

        time_1 = (hours*60 + mins);
        time_2 = (x.hours*60 + x.mins);

        if(time_1 > time_2){
                return 1;
        }else{
                return 0;
        }

}

Time Time::operator + (Time x) {
        Time duration;

        duration.hours = x.hours + hours;
        duration.mins = x.mins + mins;
        
        if(duration.hours >= 24){
                duration.hours -= 24;
        }
        if(duration.mins >=60){
                duration.mins -= 60;
        }
        
        return duration;
}

Time Time::operator - (Time x) { 
        Time duration;
        
        duration.hours = x.hours - hours;
        duration.mins = x.mins - mins;
        if(duration.mins < 0){
                duration.mins += 60;
        }
                        
        return duration;        
}

Time& Time::operator++() {
        mins++;
	if(mins >= 60){ 
                mins-=60;
                hours++;
        }
        if(hours >= 24){ 
                hours-=24;
        }
        return *this;
}

Time Time::operator ++ (int){
        Time old = *this;
        mins++;
	if(mins >= 60){
		mins-=60;
		hours++;
	}
	if(hours >= 24){
		hours-=24;
	}
        return old;
}

ostream &operator << (ostream &out, Time x) {
        out << setw(2) << setfill('0') << x.hours << ":" 
	<< setw(2) << setfill('0') <<x.mins;
        return out;
}
