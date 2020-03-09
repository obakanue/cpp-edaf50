#include <ctime>  // time and localtime
#include "date.h"
#include <iostream>
using namespace std;

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {
    this->year = y;
    this->month = m;
    this->day = d;
}

int Date::getYear() const {
	return this->year;
}

int Date::getMonth() const {
	return this->month;
}

int Date::getDay() const {
	return this->day;
}

void Date::next() {
    int daysThisMonth = daysPerMonth[this->month-1];
    if(this->day < daysThisMonth){
        this->day += 1;
    } else {
        if(this->month == 12){
            this->year += 1;
            this->month = 1;
            this->day = 1;
        } else {
            this->month += 1;
            this->day = 1;
        }
    }
}

ostream &operator<<(ostream &output, Date &date){ 
    string formattedDate;
    int year = date.getYear();
    int month = date.getMonth();
    int day = date.getDay();
    formattedDate += to_string(year);
    formattedDate += "-";
    if(month < 10){
        formattedDate += "0";
        formattedDate += to_string(month);
    } else{
        formattedDate += to_string(month);
    }
    formattedDate += "-";
    if(day < 10){
        formattedDate += "0";
        formattedDate += to_string(day);
    } else{
        formattedDate += to_string(day);
    }
    output << formattedDate;
    return output;            
}

istream &operator>>(istream  &input, Date &date){
    string inputDate;
    getline(input, inputDate);

    int sections[3];
    
    try {
        int section = inputDate.find_first_of('-');
        sections[0] = stoi(inputDate.substr(0, section));
        inputDate.erase(0, section + 1);
        
        section = inputDate.find_first_of('-');
        sections[1] = stoi(inputDate.substr(0, section));
        inputDate.erase(0, section + 1);

        sections[2] = stoi(inputDate);
    } catch (exception& e){
        input.setstate(ios::failbit);
        return input;
    }
    
    if (sections[0] > 0 && sections[1] > 0 && sections[1] > 0){
        if (sections[1] > 0 && sections[1] < 12){
            if (Date::daysPerMonth[sections[1] - 1] >= sections[2]){
                date.year = sections[0];
                date.month= sections[1];
                date.day = sections[2];
                input.setstate(ios::goodbit);
                return input;
            }
        }
    }
    
    input.setstate(ios::failbit);

    return input;
}
