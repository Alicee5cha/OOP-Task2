#pragma once
#include <ctime>		
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

class Date
{
public:
	Date();
	Date(string date);
	Date(int day, int month, int year);
	const int getDay() const;
	const int getMonth() const;
	const int getYear() const;

	string DateToString() const;
	//convert the date to a string in format (dd/mm/yyyy)

	friend ostream& operator<<(ostream& os,const Date* t);

private:
	const int getSysDay()const;
	const int getSysMonth()const;
	const int getSysYear()const;
	const int day;
	const int month;
	const int year;
};
