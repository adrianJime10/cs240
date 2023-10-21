#ifndef TIME_H
#define TIME_H
#include <string>

using namespace std;


class Time{

	public:
	
	Time(int hh, int mm, char ampm);

	int minElapsed(Time t2);
	bool compareTimes(Time t2);

	int hr;
	int min;
	string aftermorn;
};

#endif /* TIME_H */
