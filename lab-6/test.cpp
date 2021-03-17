//lab 5a
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <cstring>
#include <bits/stdc++.h>
#include <iomanip>
#include "Time.h"
#include "Time.cpp"

using namespace std;


int main() {
	Time time1, time2, duration;

	time1.read("Enter time 1");
	time2.read("Enter time 2");
	
	cout << time1.lessThan(time2) << endl;
	cout << time2.lessThan(time1) << endl;

	if (time1.lessThan(time2)) {
		duration = time2.subtract(time1);
		cout << "Starting time was ";
		time1.display();
	} else {
		duration = time1.subtract(time2);
		cout << "Starting time was ";
		time2.display();
	}
	cout << "Duration was ";
	duration.display();

	return 0;
}

