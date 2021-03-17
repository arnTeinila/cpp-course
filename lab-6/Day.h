#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <iostream>

class Day {
	public:
		Day();
		bool from_str(const string &s);
		string to_str();
		void dst(int offset);
	private:
		int day;
		string month;
		vector<Time> list;
};

#endif
