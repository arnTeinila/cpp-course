#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <iostream>

class Time {
        friend std::ostream& operator<<(std::ostream& out, const Time& s);
        //friend std::istream& operator>>(std::istream& in, Time& s);
        
        public:
                void read(const char* s);
                bool lessThan(const Time &t) const;
                Time subtract(const Time &t) const;
                void display(void) const;
                bool operator<(const Time& t) const;
        private:
                int hour;
                int min;
};

#endif
