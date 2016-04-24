/*
*	ElectricCharges Program
*
*	Programmer: Paul Badalian
*
*	Operating System: Windows 10
*
*	Compiler: MinGW g++.exe
*
*	CIS 22A Lee-Klawender
*/

#include <iostream>
#include <iomanip>

using namespace std;

void idFunction(int hwNum); //Declare idFunction

const int MAX_METER = 9999; //Initialize MAX_METER
const double BASELINE = 76.5; //Initialize BASELINE
const double FIRST_BASE = 0.18151; //Initialize first checkpoint
const double SECOND_BASE = 0.21546; //Initialize second checkpoint
const double THIRD_BASE = 0.27389; //Initialize third checkpoint
const double FOURTH_BASE = 0.34876; //Initialize fourth checkpoint

int main()
{
	int previousReading; //Declare initial meter reading
	int currentReading; //Declare current meter reading
	int adjustedCurrentReading; //Declare current reading depending on roll over
	int hoursConsumed; //Declare total hours spent
	double electricBill; //Declare total bill
	
	idFunction(3); //Call idFunction
	
	cout << "What was the previous meter reading: "; //Ask user for previous meter reading
	cin >> previousReading; //Read previous meter reading
	
	while(previousReading < 0 || previousReading > MAX_METER){ //Loop for invalid meter reading
		cout << "The meter reading cannot be less than zero or greater than the limit. Enter again: "; //Ask user to enter reading again
		cin >> previousReading; //Read for another reading
	}
	
	cout << "What is the current meter reading: "; //Ask user for current meter reading
	cin >> currentReading; //Read current meter reading
	
	while(currentReading < 0 || currentReading > MAX_METER){ //Loop for invalid meter reading
		cout << "The meter reading cannot be less than zero or greater than the limit. Enter again: "; //Ask user to enter reading again
		cin >> currentReading; //Read for another reading
	}
	
	adjustedCurrentReading = currentReading; //Evaluate changed variable to compensate for roll over
	
	if(adjustedCurrentReading < previousReading) //Check for roll over
		adjustedCurrentReading += MAX_METER + 1;
	
	hoursConsumed = adjustedCurrentReading - previousReading; //Calculate hours used
	
	for(int i = 1; i <= hoursConsumed; i++){ //Loop through every hour spent and calculate bill
		if(i > BASELINE * 2){
			electricBill += FOURTH_BASE;
		} 
		else if(i > BASELINE * 1.3 && i <= BASELINE * 2){
			electricBill += THIRD_BASE;
		}
		else if(i > BASELINE && i <= BASELINE * 1.3){
			electricBill += SECOND_BASE;
		}
		else if(i > 0 && i <= BASELINE){
			electricBill += FIRST_BASE;
		}
	}
	
	//Output the results
	cout << "\n-----------------------------------" << endl; 
	cout << setprecision(2) << fixed;
	cout << setw(25) << left << "Previous meter reading:" << setw(10) << right << previousReading << endl;
	cout << setw(25) << left << "Current meter reading:" << setw(10) << right << currentReading << endl;
	cout << setw(25) << left << "Kilowatt-hours consumed:" << setw(10) << right << hoursConsumed << endl;
	cout << setw(25) << left << "Electricity charges:" << setw(10) << right << electricBill << endl;
	cout << "-----------------------------------" << endl;
	
	
	
	return 0;
}

void idFunction(int hwNum) //Define body of idFunction
{
	cout<<"CIS 22A Programming Homework # " << hwNum << endl;
	cout <<"Badalian, Paul"<< endl << endl;
}