/****************************************************
	Calculate Item Program
	
	Programmer: Paul Badalian
	
	Operating System: Windows 10
	
	Compiler: MinGW g++.exe
	
	Description: This calculates the value of an item 
	for three consecutive years given the current
	value and the value after four years.
	
****************************************************/
#include <iostream>

using namespace std;

void idFunction(); //Declare idFunction

int main(){
	
	double currentValue, year4; //Declare input values
	double year1, year2, year3, annualAmount; //Declare calculate values
	
	idFunction(); //Call idFunction
	
	//Take input from the user for currentValue and year4
	cout << "Enter current value of the item: ";
	cin >> currentValue;
	cout << "\nEnter the value of the item after 4 years: ";
	cin >> year4;
		
	//Caluculate annualAmount, year1, year2, and year3
	annualAmount = (currentValue - year4) / 4;
	year1 = currentValue - annualAmount;
	year2 = year1 - annualAmount;
	year3 = year2 - annualAmount;
	
	//Output the calculated values
	cout << "\n-----------------------------------------------\n\n";
	cout << "After one year, the value of the item will be " << year1 << "\n\n";
	cout << "After two years, the value of the item will be " << year2 << "\n\n";
	cout << "After three years, the value of the item will be " << year3 << "\n";

	
	return 0;
}

//Describe the body of idFunction
void idFunction(){
	cout<<"CIS 22A Programming Homework #1B" << endl;
	cout <<"Badalian, Paul"<< endl<< endl;
}

/* Output

CIS 22A Programming Homework #1A
Badalian, Paul

Enter current value of the item: 30000.0

Enter the value of the item after 4 years: 14000.0

-----------------------------------------------

After one year, the value of the item will be 26000

After two years, the value of the item will be 22000

After three years, the value of the item will be 18000






CIS 22A Programming Homework #1A
Badalian, Paul

Enter current value of the item: 10000.0

Enter the value of the item after 4 years: 15000.0

-----------------------------------------------

After one year, the value of the item will be 11250

After two years, the value of the item will be 12500

After three years, the value of the item will be 13750






CIS 22A Programming Homework #1A
Badalian, Paul

Enter current value of the item: 123456.0

Enter the value of the item after 4 years: 56789.0

-----------------------------------------------

After one year, the value of the item will be 106789

After two years, the value of the item will be 90122.5

After three years, the value of the item will be 73455.8




*/