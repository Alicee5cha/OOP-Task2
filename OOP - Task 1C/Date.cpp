#include <iostream>
#include <string>
#include <ctime>
#include <time.h>
#include "Date.h"

using namespace std;
Date::Date()
{
}
Date::Date(string date)
{
	year = stoi(date.substr(0, 4));
	month = stoi(date.substr(5, 2));
	day = stoi(date.substr(8, 2));

	
}
Date::Date(int d, int m, int y):day(d),month(m),year(y)
{

}

int Date::getDay()
{
	return day;
}
int Date::getMonth()
{
	return month;
}
int Date::getYear()
{
	return year;
}

void Date::getSystemTime(int& hrs, int& mins, int& secs)
{ //get time from system
	//set to system time
	time_t now(time(0));
	struct tm t;
	localtime_s(&t, &now);
	hrs = t.tm_hour;
	mins = t.tm_min;
	secs = t.tm_sec;
}

const string Date::timeToString(int h, int m, int s)
{ //convert the time to a string in 24-h digital clock format (00:00:00)
	ostringstream os;
	const char prev(os.fill('0'));
	os << setw(2) << h << ":"
		<< setw(2) << m << ":"
		<< setw(2) << s;
	os.fill(prev);
	return os.str();
}

const string Date::getTime()
{ //return the current time in a string format
	int hrs, mins, secs;		//hold the current time
	getSystemTime(hrs, mins, secs);
	return timeToString(hrs, mins, secs);
}

void Date::getSystemDate(int& day, int& month, int& year)
{ //get date from system
	time_t now(time(0));
	struct tm t;
	localtime_s(&t, &now);
	day = t.tm_mday;
	month = t.tm_mon + 1;
	year = t.tm_year + 1900;
}

string Date::dateToString(int day, int month, int year)
{ //convert the date to a string in format (yyyy-mm-dd)
	std::string os;
	os = year + "-";
	os += month + "-" + day;
	
	return os;
}

const string Date::getDate()
{ //return the current date in a string format
	int day, month, year;		//hold the current date
	getSystemDate(day, month, year);
	return dateToString(day, month, year);
}

void Date::CurrentDate(int day, int month, int year)
{

}

ostream& operator<<(ostream& os, const Date* t)
{
	os << t->year << "-";

	if (t->month < 10)
		os << "0";

	os << t->month << "-";

	if (t->day < 10)
		os << "0";

	os << t->day;

	return os;
};