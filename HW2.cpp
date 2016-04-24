/* HW #2 Calculate temperature program
 *
 * Programmer: Paul Badalian
 *
 * Operating System: Windows 10
 *
 * Compiler: GNU g++.exe
 *
 * Professor: Cynthia Lee-Klawender CIS 22A
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

const double fDifference = 32; //Constant value for Farenheight constant difference
const double fRatio = 5.0/9.0; //Constant value for Farenheight difference ratio

void idFunction(int); //Since function is only declared the parameter name doesn't need to be specified

int main(){
	
	string cityName; //city name that is to be read from the user
	double degreesF; //degrees in Farenheight to be read from the user
	double degreesC; //holds degreesF in Celcius
	double oldWindChillF; //will hold calculation of old wind chill using windSpeed and degreesF
	double oldWindChillC; //holds oldWindChillF in terms of Celcius
	double newWindChillF; //will hold calculation of new wind chill using windSpeed and degreesF
	double newWindChillC; //holds newWindChillF in terms of Celcius
	int windSpeed; //wind speed in miles per hour to be read from the user
	
	idFunction(2); //Call idFunction
	
	cout << "Enter the name of the city: ";
	getline(cin, cityName); //Reads the cityName from user
	cout << "Enter the temperature of " << cityName << " in Farenheight: ";
	cin >> degreesF; //Reads degressF from user
	cout << "Enter the wind Speed: ";
	cin >> windSpeed; //Reads wind speed from user
	
	degreesC = (degreesF - fDifference) * (fRatio); //Calculate degreesC from degressF
	oldWindChillF = 0.0817 * (3.71 * sqrt(windSpeed) + 5.81 - 0.25 * windSpeed) * (degreesF - 91.4) + 91.4; //Calculate oldWindChillF
	oldWindChillC = (oldWindChillF - fDifference) * (fRatio); //Calculate oldWindChillF in Celcius
	newWindChillF = 35.74 + (0.6215 * degreesF) - (35.75 * pow(windSpeed, 0.16)) + (0.4275 * degreesF * pow(windSpeed, 0.16)); //Calculate newWindChillF
	newWindChillC = (newWindChillF - fDifference) * (fRatio); //Calculate newWindChillF in Celcius
	
	cout << "\n" << setprecision(2) << fixed << "----------------------------------------" << endl;
	cout << setw(20) << left << "City:" << setw(20) << right << cityName << endl; //Output city name
	cout << setw(20) << left << "Temperature (F):" << setw(20) << right << degreesF << endl; //Output degreesF
	cout << setw(20) << left << "Temperature (C):" << setw(20) << right << degreesC << endl; //Output degreesC
	cout << setw(20) << left << "Wind Speed (MPH):" << setw(17) << right << windSpeed << endl; //Output wind speed
	cout << setw(20) << left << "Old WindChill (F):" << setw(20) << right << oldWindChillF << endl; //Output oldWindChillF
	cout << setw(20) << left << "Old WindChill (C):" << setw(20) << right << oldWindChillC << endl; //Output oldWindChillC
	cout << setw(20) << left << "New WindChill (F):" << setw(20) << right << newWindChillF << endl; //Output newWindChillF
	cout << setw(20) << left << "New WindChill (C):" << setw(20) << right << newWindChillC << endl; //Output newWindChillC
	cout << "----------------------------------------" << endl;

	return 0; 
}

void idFunction(int hwNum){ 
	
	cout << "CIS 22A Programming Homework # " << hwNum << endl;
	cout << "Badalian, Paul" << endl << endl;

}