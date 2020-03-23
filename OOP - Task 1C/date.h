#pragma once
#include <ctime>		
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

class Date
{
public:
	Date(string date);
	Date(int day, int month, int year);
	static void CurrentDate(int day, int month, int year);
	int getDay();
	int getMonth();
	int getYear();
	~Date();

	void getSystemTime(int& hrs, int& mins, int& secs);
	//get time from system

	const string timeToString(int h, int m, int s);
	//convert the time to a string in 24-h digital clock format (00:00:00)

	const string getTime();
	//return the current time in a string format

	void getSystemDate(int& day, int& month, int& year);
	//get date from system

	const string dateToString(int day, int month, int year);
	//convert the date to a string in format (dd/mm/yyyy)

	const string getDate();
	//return the current date in a string format

private:
	int day;
	int month;
	int year;
	tm date;
};
