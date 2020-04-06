#include <iostream>
#include <string>
#include <ctime>
#include <time.h>
#include "Date.h"
using namespace std;

Date::Date():day(getSysDay()),month(getSysMonth()),year(getSysYear())
{
}

Date::Date(string date):
year(stoi(date.substr(0, 4))),
month(stoi(date.substr(5, 2))),
day(stoi(date.substr(8, 2)))
{}

Date::Date(int d, int m, int y):day(d),month(m),year(y)
{}

const int Date::getDay() const
{
	return day;
}
const int Date::getMonth() const 
{
	return month;
}
const int Date::getYear() const 
{
	return year;
}

const int Date::getSysYear() const
{
	time_t now = time(0);
	tm t; 
	localtime_s(&t,&now);
	return t.tm_year + 1900;
}
const int Date::getSysMonth() const
{
	time_t now = time(0);
	tm t;
	localtime_s(&t, &now);
	return t.tm_mon+1;
}
const int Date::getSysDay() const
{
	time_t now = time(0);
	tm t;
	localtime_s(&t, &now);
	return t.tm_mday;
}


string Date::DateToString() const
{ //convert the date to a string in format (yyyy-mm-dd)
	std::string os="";
	os = to_string(year) + "-";
	if (month < 10)
		os += "0" + to_string(month) + "-";
	else
		os += to_string(month) + "-";

	if (day < 10)
		os += "0" + to_string(day);
	else
		os += to_string(day);
	
	return os;
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