/*
You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

#include <iostream>

using namespace std;

string whatDay(int, int, int);
int countSundays(int, int, int);
bool isLeapYear(int);

int months [] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void){

	int day = 2; //represents day of the week
	int month = 1;
	int year = 1901;

	cout << countSundays(day, month, year) << endl;
}

int countSundays(int day, int month, int year){

	int count = 0;

	while(year < 2001){

		if(isLeapYear(year)) months[1] = 29;
		else months[1] = 28;

		for(int i = 1; i <= months[month-1]; i++){ //loop through the number of days in each month
			if(day == 7 && i == 1) count++; //if the day is sunday and it lies on the first of the month, increment the counter
			day++;
			if(day > 7) day = 1;
		}

		month++;
		if(month > 12){
			month = 1;
			year++;
		}
	}

	return count;
}

bool isLeapYear(int year){
	if(year % 100 == 0 && year % 400 > 0) return false;
	if(year % 4 == 0) return true;
}