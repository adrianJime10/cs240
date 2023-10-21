#include "time.h"

Time::Time(int hh, int mm, string ampm){
	hr = hh;
	min = mm;
	aftermorn = ampm;
}

int minElapsed(Time t2){
	if(aftermorn=="a" && t2.aftermorn=="a"){
		if(hr==12&&t2.hr==12){
			return t2.min-min;
		}
		else if(hr==12){
			return ((t2.hr*60)+t2.min)-min;
		}
		else{
			return ((t2.hr*60)+t2.min)-((hr*60)+min);
		}
	}
	else if(aftermorn=="a" && t2.aftermorn=="p"){
		if(hr==12&&t2.hr==12){
			return ((t2.hr*60)+t2.min)-min;
		}
		else if(hr==12){
			return ((t2.hr+12)*60+t2.min)-min;
		}
		else if(t2.hr==12){
			return ((t2.hr)*60+t2.min)-((hr*60)+min);
		}
		else{
			return ((t2.hr+12)*60+t2.min)-((hr*60)+min);
		}
	}
	else{
		if(hr==12&&t2.hr==12){
			return t2.min-min;
		}
		else if(hr==12){
			return ((t2.hr+12)*60+t2.min)-((hr*60)+min);
		}
		else{
			return ((t2.hr+12)*60+t2.min)-((hr+12)*60+min);
		}
	}
}

bool Time::compareTimes(Time t2){
	if(hr==12&&t2.hr==12){
		if(aftermorn=="a" && t2.aftermorn=="p"){
			return (min<(t2.hr)*60+t2.min);
		}
		else{
			return (min<t2.min);
		}	
	}
	else if(hr==12){
		if(aftermorn=="a" && t2.aftermorn=="a"){
			return (min<((t2.hr)*60)+t2.min);
		}
		else if(aftermorn=="a" && t2.aftermorn=="p"){
			return (min<((t2.hr+12)*60)+t2.min);
		}
		else{
			return ((hr)*60+min<((t2.hr+12)*60)+t2.min);
		}
	}
	else if(t2.hr==12){
		if(aftermorn=="a" && t2.aftermorn=="a"){
			return ((hr)*60+min<t2.min);
		}
		else if(aftermorn=="a" && t2.aftermorn=="p"){
			return ((hr+12)*60+min<t2.min);
		}
		else{
			return ((hr+12)*60+min<((t2.hr)*60)+t2.min);
		}
	}
	else{
		if(aftermorn=="a" && t2.aftermorn =="p"){
			return (hr < t2.hr+12);
		}
		else if(t1.aftermorn=="a" && t2.aftermorn=="a"){
			return (hr*60+min<t2.hr*60+t2.min);
		}
		else if(aftermorn=="p" && t2.aftermorn=="p"){
			return ((hr+12)*60+min<(t2.hr+12)*60+t2.min);
		}
	}
}
