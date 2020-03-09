#include <iostream>
#include <iomanip> // for setw and setfill
#include "date.h"
#include <sstream>
using namespace std;

template <typename T>
string toString(T &t){
    stringstream s;
    s << t;
    return s.str();
}

string toString(Date &t){
    stringstream s;
    s << t;
    return "Date: " + s.str();
}


template <typename R>
R string_cast(const std::string &s){
    std::stringstream ss;
    R r;
    ss << s;
    ss >> r; 
    return r;
}

/*
 * Prints the date d in the format yyyy-mm-dd. You shall replace this
 * function with an overloaded operator<<, and add an overloaded operator>>.
 *
 */
void print(const Date& d) {
    cout << setw(4) << setfill('0') << d.getYear() << '-';
    cout << setw(2) << setfill('0') << d.getMonth() << '-';
    cout << setw(2) << setfill('0') << d.getDay();
}

int main() {
	// Check input and output of dates. Uncomment the following when you 
	// have added operator>> and operator<<.
    

    // Test template
    double d = 1.234;
    Date today;
    string sd = toString(d);
    string st = toString(today);
    cout << "Double: " << d << ", " << st << endl;

    try {
        int i = string_cast<int>("123");
        double d = string_cast<double>("12.34");
        Date date = string_cast<Date>("2015-01-10");
        cout << "Integer: " << i << ", Double: " << d << ", Date: " << date << endl;
    } catch (std::invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

	bool cont = true;
	while (cont) {
		cout << "Type a date: ";
        
		Date aDate;
		cin >> aDate;
		if (cin.eof()) {
			cont = false;
		} else if (!cin.good()) {
			cout << "Wrong input format" << endl;
			// restore stream state and ignore the rest of the line
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else {
			cout << "Output: " << aDate << endl;
		}
	}
	
	
	// Check 'next' by creating an object describing today's date, then
	// printing dates more than a month ahead
    cout << "--- Today and more than a month ahead:" << endl;
	Date d1;
	print(d1);
    cout << endl;
	for (int i = 1; i <= 35 ; ++i) {
		d1.next();
		print(d1);
        cout << endl;
	}
	
	// Check so 'next' functions correctly from one year to the next
    cout << "--- New Year's Eve and the next day:" << endl;
	Date d2(2013, 12, 31);
	print(d2);
    cout << endl;
	d2.next();
	print(d2);
    cout << endl;
}
