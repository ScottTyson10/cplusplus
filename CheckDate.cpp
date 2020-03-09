//---------------------------------------------------------------------------
//Programmer: 	Scott Tyson 2120177
//Date 			1/10/2016
//Reference		Assignment 11 exercise 27
//Folder	H:\ My Documents\ IT5156\ Assignment 11 
//Description	  Check that givin date is valid
//Guarantee  	  Program works to full specifications
//---------------------------------------------------------------------------


#include <iostream>
#include <conio.h>
#include <math.h>
#pragma hdrstop
using namespace std;
#include <iomanip>
#include <windows.h>
#include <tchar.h>

int checkYear();
int checkMonth();

class Date
{
private:
	int year;
	int month;
	int day;

	int checkFebruary(int tempDay);
	int checkSecondaryMonth(int tempDay);
	int checkMainMonth(int tempDay);

public:

	Date()
	{
		year = 1800;
		month = 1;
		day = 1;
	}

	Date (int y, int m)
	{
		year = y;
		month = m;
	}

	void setYear(int y)
	{
		year = y;
	}
	
	int getYear()
	{
		return year;
	}

	void setMonth(int m)
	{
		month = m;
	}
	
	int getMonth()
	{
		return month;
	}

	void setDay();

	int getDay()
	{
		return day;
	}
	
	void printDate();
};


//---------------------------------------------------------------------------

int _tmain(int argc, _TCHAR* argv[])
{
	int year;
	int month;

	Date defaultDate;

	year = checkYear();
	month = checkMonth();

	Date date2(year, month);

	date2.setDay();

	date2.printDate();	


	return 0;
}
//---------------------------------------------------------------------------
//checkYear()
//Purpose: Enter a year, and check that it is within the range
//Input: tempYear
//Output: tepYear
//---------------------------------------------------------------------------
int checkYear()
{
	int tempYear;

	cout << "Enter year by number (Must be between 1800 and 2800): ";
	cin >> tempYear;

	while (tempYear < 1800 || tempYear > 2800)
	{
		cout << endl << "Year is not within range!" << endl
			<< "Enter year in number form (Must be between 1800 and 2800): ";
		cin >> tempYear;
	}
	return tempYear;
}

//---------------------------------------------------------------------------
//int checkMonth()
//Purpose: Enter a month, and check that it is valid
//Input: tempMonth
//Output: tempMonth
//---------------------------------------------------------------------------
int checkMonth()
{
	int tempMonth;

	cout << endl << "Enter month by number (Numbers 1 - 12): ";
	cin >> tempMonth;

	while (tempMonth < 1 || tempMonth > 12)
	{
		cout << endl << "Month is not within range!" << endl
			<< "Enter month by number (Numbers 1 - 12): ";
		cin >> tempMonth;
	}
	return tempMonth;
}
//---------------------------------------------------------------------------
//int setDay
//Purpose: Enter a month, and check that it is valid
//Input: tempMonth
//Output: tempMonth
//---------------------------------------------------------------------------
void Date::setDay()
{
	int tempDay;

	cout << endl << "Enter day by number"
		<< "(Numbers 1 to 28-29-30-31 depending on month): ";
	cin >> tempDay;

	if (month == 2)
		checkFebruary(tempDay);
	else
		if (month == 4 || month == 6 || month == 9 || month == 11)
			checkSecondaryMonth(tempDay);
		else
			checkMainMonth(tempDay);

	day = tempDay;

}
//---------------------------------------------------------------------------
//int setDay
//Purpose: Enter a month, and check that it is valid
//Input: tempMonth
//Output: tempMonth
//---------------------------------------------------------------------------
int Date::checkFebruary(int tempDay)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				while (tempDay > 29)
				{
					cout << "Selected month does not have that many days!" << endl
						<< endl << "Enter day by number "
						<< "(Numbers 1 to 29): ";
					cin >> tempDay;
				}	
			}
			else
			{
				while (tempDay > 28)
				{
					cout << "Selected month does not have that many days!" << endl
						<< endl << "Enter day by number "
						<< "(Numbers 1 to 28): ";
					cin >> tempDay;
				}
			
			}
		}
		else
		{
			while (tempDay > 29)
			{
				cout << "Selected month does not have that many days!" << endl
					<< endl << "Enter day by number "
					<< "(Numbers 1 to 29): ";
				cin >> tempDay;
			}
			
		}
	}
	else
	{
		while (tempDay > 28)
		{
			cout << "Selected month does not have that many days!" << endl
				<< endl << "Enter day by number "
				<< "(Numbers 1 to 28): ";
			cin >> tempDay;
		}	
	}
}
//---------------------------------------------------------------------------
//int checkMainMonth( int tempDay )
//Purpose: Check if the entered day exceeds the limit of 30 day months
//Input: tempDay
//Output: corrected tempDay
//---------------------------------------------------------------------------
int Date::checkMainMonth(int tempDay)
{
	while (tempDay > 31)
	{
		cout << "Selected month does not have that many days!" << endl
			<< endl << "Enter day by number "
			<< "(Numbers 1 to 28-29-30-31 depending on month): ";
		cin >> tempDay;
	}
	return tempDay;
}
//---------------------------------------------------------------------------
//int checkSecondaryMonth( int tempDay )
//Purpose: Check if the entered day exceeds the limit of 30 day months
//Input: tempDay
//Output: corrected tempDay
//---------------------------------------------------------------------------
int Date::checkSecondaryMonth(int tempDay)
{
	while (tempDay > 30)
	{
		cout << "Selected month does not have that many days!" << endl
			<< endl << "Enter day by number "
			<< "(Numbers 1 to 28-29-30-31 depending on month): ";
		cin >> tempDay;
	}
	return tempDay;
}
//---------------------------------------------------------------------------
//void printDate( int day, int month, int year )
//Purpose: Print the date in the fromat selected by the user
//Input: The various date values and the choice of format
//Output: Printed date
//---------------------------------------------------------------------------
void Date::printDate()
{
	char choice;
	char delimiter;
	char MonthNames[12][12] = { "January", "February", "March", "April",
		"May", "June", "July", "August", "September", "October",
		"November", "December" };

	cout << endl << endl
		<< "Choose format to print date" << endl
		<< "Press 'a' to print date as dd*mm*yyyy "
		<< "where * is your choice of delimiter" << endl << endl
		<< "Press 'b' to print date as dd MonthName yyyy" << endl << endl
		<< "Enter choice: ";
	choice = _getch();

	while (choice != 'a' && choice != 'b')
	{
		cout << endl << "Invalid choice of format!"
			<< endl << endl
			<< "Choose format to print date" << endl
			<< "Press 'a' to print date as dd*mm*yyyy "
			<< "where * is your choice of delimiter" << endl << endl
			<< "Press 'b' to print date as dd MonthName yyyy" << endl << endl
			<< "Enter choice: ";
		choice = _getch();
	}

	if (choice == 'a')
	{
		cout << endl << "Enter your choice of delimiter: ";
		delimiter = _getch();

		cout << endl << endl << "The date is: "
			<< day << delimiter << month << delimiter << year;
	}

	else
	{
		if (choice == 'b')
		{
			cout << endl << endl << "The date is: "
				<< day << " " << MonthNames[month - 1] << " " << year;
		}
	}
}
//---------------------------------------------------------------------------