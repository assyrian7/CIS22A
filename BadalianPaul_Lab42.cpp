//Lab Exercise 4.2
//  More practice of logical operators and switch statement
// Name: Paul Badalian

#include <iostream>
using namespace std;

// function prototype declaration
void idFunction(double exNum);

int main()
{
	int month;		// month number (1-12), input
	int day;		// day of the month, input
	string monthName; // month name
	int daysInMonth=0; // # of days in the input month
	bool invalidInput;// true if input is invalid, false otherwise

    idFunction(4.2);

	cout<<"Enter a date in the form MM DD: ";
	cin>>month>>day;

	invalidInput=false; // initialize flag
	switch(month)
	{
		case 1: monthName = "January"; break;
		case 2: monthName = "February"; break;
		case 3: monthName = "March"; break;
		case 4: monthName = "April"; break;
		case 5: monthName = "May"; break;
		case 6: monthName = "June"; break;
		case 7: monthName = "July"; break;
		case 8: monthName = "August"; break;
		case 9: monthName = "September"; break;
		case 10: monthName = "October"; break;
		case 11: monthName = "November"; break;
		case 12: monthName = "December"; break;
		default: monthName = "Invalid Month";
			   invalidInput = true; // set flag
	} // end switch

	if( !invalidInput )
	{
	// WRITE A SWITCH STATEMENT HERE TO ASSIGN THE DAYS in the input MONTH
	//     USE 28 for 2 (February)
		switch(month)
		{
			case 1:
				daysInMonth = 31;
				break;
			case 2:
				daysInMonth = 28;
				break;
			case 3:
				daysInMonth = 31;
				break;
			case 4:
				daysInMonth = 30;
				break;
			case 5:
				daysInMonth = 31;
				break;
			case 6:
				daysInMonth = 30;
				break;
			case 7:
				daysInMonth = 31;
				break;
			case 8:
				daysInMonth = 30;
				break;
			case 9:
				daysInMonth = 31;
				break;
			case 10:
				daysInMonth = 30;
				break;
			case 11:
				daysInMonth = 31;
				break;
			case 12:
				daysInMonth = 30;
				break;
			default:
				invalidInput = true;
				break;
		}


	}


	// WRITE ONE (NOT MORE) IF STATEMENT WITH LOGICAL OPERATORS
	//    WHICH WILL TEST IF the input day is between
	//	1 and the daysInMonth, inclusive or not
	//    and assign true to the invalidInput flag if NOT
	if(day < 1 || day > daysInMonth){
	
		invalidInput = true;
	}

	// end if

	if( invalidInput )
		cout<<"Invalid date entered\n";
	else
		cout<<monthName<<" "<<day<<endl;

	return 0;
}// end main

void idFunction(double exNum)
{
	cout<<"CIS 22A Exercise #" << exNum << endl;
	cout <<"Badalian, Paul"<< endl;
}

