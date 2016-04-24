// LAB EXERCISE 5.0
// UPDATE THIS PROGRAM SO YOU USE A WHILE LOOP FOR EACH INPUT VALUE
// The loop for the choice will loop if the input choice isn't 1-4 inclusive
// The loop for the months will loop if the input months isn't 1-12 inclusive
#include <iostream>
#include <iomanip>
using namespace std;

// Constants for membership rates
const double ADULT = 40.0,
            SENIOR = 30.0,
            CHILD = 20.0;

// Constants for menu choices
const int ADULT_CHOICE = 1,
         CHILD_CHOICE = 2,
         SENIOR_CHOICE = 3,
         QUIT_CHOICE = 4;

int main()
{
   int choice;       // To hold a menu choice
   int months;       // To hold the number of months
   double charges;   // To hold the monthly charges

   // Display the menu and get a choice.
   cout << "\t\tHealth Club Membership Menu\n\n";
   cout << "1. Standard Adult Membership\n";
   cout << "2. Child Membership\n";
   cout << "3. Senior Citizen Membership\n";
   cout << "4. Quit the Program\n\n";
   cout << "Enter your choice: ";
   cin >> choice;

   // PUT INPUT VALIDATION for choice while LOOP HERE*****
   // Set the numeric ouput formatting.
   while(choice < 1 || choice > 4){
	   cout << "Invalid choice enter again: ";
	   cin >> choice;
   }
   cout << fixed << showpoint << setprecision(2);

   if( choice != QUIT_CHOICE )
   {
        cout << "For how many months? ";
        cin >> months;
        // PUT INPUT VALIDATION for months while LOOP HERE*****
        // Respond to the user's menu selection.
		while(months < 1 || months > 12){
			cout << "Invalid input for months enter again: ";
			cin >> months;
		}
       switch( choice )
       {
           case ADULT_CHOICE:
                charges = months * ADULT;
                break;
            case CHILD_CHOICE:
                charges = months * CHILD;
                break;
            case SENIOR_CHOICE:
                charges = months * SENIOR;
                break;
       } // end switch
       cout << "The total charges are $" << charges << endl;
   }
   else
   {
      cout << "You chose to quit the program.\n";
   }
   return 0;
}
