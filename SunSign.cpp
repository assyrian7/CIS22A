/*
*	SunSign Program
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

const int MAX_MONTHS = 12; //Initialize value for the maximum amount of months entered
const int MAX_DAYS = 31; //Initialize value for the maximum amount of days entered
const int MIN_YEAR = 1900; //Initialize value for the minimum year entered
const int MAX_YEAR = 2100; //Initialize value for the maximum year entered

//Leap year logic year % 4 == 0 && year % 100 != 0

void displaySunSignInfo(char sunSign); //Declare output function for sun signs
void idFunction(int hwNum); //Declare idFunction

int main(){

	int month; //Declare month variable
	int day; //Declare day variable
	int year; //Declare year variable
	char sunSign; //Declare sunSign variable
	char repeat; //Declare repeat variable

	idFunction(4); //Call idFunction with parameter 4

	do{ //Loop for the entire program
		cout << "Enter month, day, and year as MM DD YYYY: "; //Ask user to input birth date
		cin >> month >> day >> year; //Read birth date

		while(month < 1 || month > MAX_MONTHS || day < 1 || day > MAX_DAYS || year < MIN_YEAR || year > MAX_YEAR){ //Loop through possible invalid dates
			cout << "Error accepting date enter again: "; //Ask user for another date
			cin >> month >> day >> year; //Read the other date
		}
		cout << "\n";

		//sunSign = ""; //Refresh Sun Sign

		switch(month){ //Switch for determining the sun sign
			case 1:
				if(day >= 1 && day <= 19)
					sunSign = 'G';
				else if(day >= 20 && day <= 31)
					sunSign = 'W';
				break;
			case 2:
				if(day >=1 && day <= 18)
					sunSign = 'W';
				else if(day >= 19 && day <= 28)
					sunSign = 'F';
				else if(day == 29 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
					sunSign = 'F';
				else
					sunSign = 'X';
				break;
			case 3:
				if(day >= 1 && day <= 20)
					sunSign = 'F';
				else if(day >= 21 && day <= 31)
					sunSign = 'R';
				break;
			case 4:
				if(day >= 1 && day <= 19)
					sunSign = 'R';
				else if(day >= 20 && day <= 30)
					sunSign = 'B';
				else
					sunSign = 'X';
				break;
			case 5:
				if(day >= 1 && day <= 20)
					sunSign = 'B';
				else if(day >= 21 && day <= 31)
					sunSign = 'T';
				break;
			case 6:
				if(day >= 1 && day <= 20)
					sunSign = 'T';
				else if(day >= 21 && day <= 30)
					sunSign = 'C';
				else
					sunSign = 'X';
				break;
			case 7:
				if(day >= 1 && day <= 22)
					sunSign = 'C';
				else if(day >= 23 && day <= 31)
					sunSign = 'L';
				break;
			case 8:
				if(day >= 1 && day <= 22)
					sunSign = 'L';
				else if(day >= 23 && day <= 31)
					sunSign = 'V';
				break;
			case 9:
				if(day >= 1 && day <= 22)
					sunSign = 'V';
				else if(day >= 23 && day <= 30)
					sunSign = 'S';
				else
					sunSign = 'X';
				break;
			case 10:
				if(day >= 1 && day <= 22)
					sunSign = 'S';
				else if(day >= 23 && day <= 31)
					sunSign = 'N';
				break;
			case 11:
				if(day >= 1 && day <= 21)
					sunSign = 'N';
				else if(day >= 22 && day <= 30)
					sunSign = 'A';
				else
					sunSign = 'X';
				break;
			case 12:
				if(day >= 1 && day <= 21)
					sunSign = 'A';
				else if(day >= 22 && day <= 31)
					sunSign = 'G';
				break;
			default:
				sunSign = 'X';
				break;
		}

		displaySunSignInfo(sunSign); //Call output function for sun sign
		cout << "\nWould you like to read for another sign? (Enter y for yes or n for no): "; //Ask user if they would like to determine another date
		cin >> repeat; //Read repeat decision

	}while(repeat != 'n' && repeat != 'N');

	return 0;

}

void displaySunSignInfo(char sunSign){ //Define sun sign output function

	switch(sunSign){ //Switch on the sun sign to output details of the sign
		case 'G':
			cout << "\'G\': Your Sun Sign is Capricorn - The Goat" << endl;
			cout << "      Capricorn's are also philosophical signs and are highly intelligent too." << endl;
			cout << "      They are good organizers, and they achieve their goals by purposeful," << endl;
			cout << "      systematic means." << endl;
			break;
		case 'W':
			cout << "\'W\': Your Sun Sign is Aquarius - The Water Bearer" << endl;
			cout << "      Aquarian's will take up any cause, and are humanitarians of the zodiac." << endl;
			cout << "      They are honest, loyal and highly intelligent." << endl;
			break;
		case 'F':
			cout << "\'F\':  Your Sun Sign is Pisces - The Fish" << endl;
			cout << "      They are honest, unselfish, trustworthy and often have quiet dispositions." << endl;
			cout << "      They can be overcautious and sometimes gullible." << endl;
			break;
		case 'R':
			cout << "\'R\':  Your Sun Sign is Aries - The Ram" << endl;
			cout << "      Aries people are creative, adaptive, and insightful. Aries are fire signs, and" << endl;
			cout << "      so too is their personality." << endl;
			break;
		case 'B':
			cout << "\'B\':  Your Sun Sign is Taurus - The Bull" << endl;
			cout << "      Stubborn by nature, the Taurus will stand his/her ground to the bitter end." << endl;
			cout << "      But that's okay because the Taurus is also a loving, sympathetic and" << endl;
			cout << "      appreciative sign." << endl;
			break;
		case 'T':
			cout << "\'T\':  Your Sun Sign is Gemini - The Twins" << endl;
			cout << "      Flexibility, balance and adaptability are the keywords for the Gemini. They" << endl;
			cout << "      tend to have a duality to their nature, and can sometimes be tough to predict" << endl;
			cout << "      how they will react." << endl;
			break;
		case 'C':
			cout << "\'C\':  Your Sun Sign is Cancer - The Crab" << endl;
			cout << "      Cancerians love home-life, family and domestic settings. They are" << endl;
			cout << "      traditionalists, and enjoy operating on a fundamental level." << endl;
			break;
		case 'L':
			cout << "\'L\':  Your Sun Sign is Leo - The Lion" << endl;
			cout << "      The zodiac signs and meanings of Leo is about expanse, power and" << endl;
			cout << "      exuberance. Leo's are natural born leaders, and have a tendency to be" << endl;
			cout << "      high-minded and vocal about their opinions." << endl;
			break;
		case 'V':
			cout << "\'V\':  Your Sun Sign is Virgo - The Virgin" << endl;
			cout << "      Virgo's have keen minds, and are delightful to talk with, often convincing" << endl;
			cout << "      others of outlandish tales with ease and charm. Virgo's are inquisitive and" << endl;
			cout << "      are very skilled at drawing information from people." << endl;
			break;
		case 'S':
			cout << "\'S\':  Your Sun Sign is Libra - The Scales" << endl;
			cout << "      As their zodiac signs and meanings would indicate, Libra's are all about" << endl;
			cout << "      balance, justice, equanimity and stability.  Libra's are very understanding," << endl;
			cout << "      caring, and often the champion of underdogs." << endl;
			break;
		case 'N':
			cout << "\'N\':  Your Sun Sign is Scorpio - The Scorpion" << endl;
			cout << "      The Scorpio is often misunderstood. These personalities are bold and are" << endl;
			cout << "      capable of executing massive enterprises with cool control and confidence." << endl;
			break;
		case 'A':
			cout << "\'A\':  Your Sun Sign is Sagittarius - The Archer" << endl;
			cout << "      They have great ability for focus, and can be very intense.  They are not very" << endl;
			cout << "      patient and expect quick results." << endl;
			break;
		case 'X':
			cout << "There is no sign for the date you entered." << endl;
			break;
		default:
			break;

	}

}
void idFunction(int hwNum){ //Define id Function

	cout<<"CIS 22A Programming Homework # " << hwNum << endl; //Output homework details
	cout <<"Badalian, Paul"<< endl << endl; //Output author details

}

/* Output
CIS 22A Programming Homework # 4
Badalian, Paul

Enter month, day, and year as MM DD YYYY: 11 22 1993

'A':  Your Sun Sign is Sagittarius - The Archer
      They have great ability for focus, and can be very intense.  They are not
very
      patient and expect quick results.

Would you like to read for another sign? (Enter y for yes or n for no): y
Enter month, day, and year as MM DD YYYY: 11 21 1992

'N':  Your Sun Sign is Scorpio - The Scorpion
      The Scorpio is often misunderstood. These personalities are bold and are
      capable of executing massive enterprises with cool control and confidence.


Would you like to read for another sign? (Enter y for yes or n for no): Y
Enter month, day, and year as MM DD YYYY: 02 29 1988

'F':  Your Sun Sign is Pisces - The Fish
      They are honest, unselfish, trustworthy and often have quiet dispositions.

      They can be overcautious and sometimes gullible.

Would you like to read for another sign? (Enter y for yes or n for no): k
Enter month, day, and year as MM DD YYYY: 02 29 2100

There is no sign for the date you entered.

Would you like to read for another sign? (Enter y for yes or n for no): 3
Enter month, day, and year as MM DD YYYY: 00 01 2000
Error accepting date enter again: 01 00 2000
Error accepting date enter again: 01 31 1899
Error accepting date enter again: 01 31 2101
Error accepting date enter again: 01 32 2000
Error accepting date enter again: 13 31 2000
Error accepting date enter again: 01 20 1900

'W': Your Sun Sign is Aquarius - The Water Bearer
      Aquarian's will take up any cause, and are humanitarians of the zodiac.
      They are honest, loyal and highly intelligent.

Would you like to read for another sign? (Enter y for yes or n for no): N

Process returned 0 (0x0)   execution time : 208.806 s
Press any key to continue.
*/













