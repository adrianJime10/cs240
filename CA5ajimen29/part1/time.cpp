#include "time.h"

Time::Time(int hh, int mm, string ampm){
	hr = hh;
	min = mm;
	if(ampm == "am") aftermorn = 1;
	else aftermorn = 2;
}

Time::compareTimes(t1,t2){
	if(((t1.hr *100*aftermorn) + (t1.min))>((t2.hr*100*aftermorn)+(t1.min))) return t1;
	else return t2;
}
