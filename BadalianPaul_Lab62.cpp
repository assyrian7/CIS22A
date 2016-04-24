// This program displays a hot beverage menu and prompts the user to
// make a selection. A switch statement determines which item the user
// has chosen. A do-while loop repeats until the user selects item E
// from the menu.

// 
#include <iostream>
#include <iomanip>

using namespace std;

// PUT FUNCTION PROTOTYPE DECLARATION HERE for readInput
void readInput(char &beverage, int &numCups);
int getInteger(string prompt,
		int minInt,
		int maxInt);
double calcCost(char beverage, int numCups);

int main()
{

  // Fill in the code to define an integer variable called numCups,
    int numCups;

  // a floating point variable called cost,
    float cost;

  // and a character variable called beverage
    char beverage;

    char repeatAnswer;

    cout << fixed << showpoint << setprecision(2);
    do
    {
    
		readInput(beverage, numCups);
        // Fill in the code to begin a switch statement
        // that is controlled by beverage

        cost = calcCost(beverage, numCups);//switch is in the fcn

        cout << "The total cost is $ " << cost << endl;

        cout<<"Do you want to purchase more? (n for no): ";
        cin>>repeatAnswer;

	  // Fill in the code to finish the do-while statement with the
	  // condition that repeatAnswer isn't 'n' nor 'N'.

	}while( repeatAnswer != 'n' && repeatAnswer != 'N' );
// OR   (!(repeatAnswer == 'n' || repeatAnswer == 'N') ); 


	  // Fill in the appropriate return statement
	return 0;

}// end main

// FILL IN THE FOLLOWING FUNCTION so you declare reference
//    parameters for beverage (char) and numCups (int)
//    and then fill in the body AS SPECIFIED IN MAIN:
void readInput(char &beverage, int &numCups)
{
	// FILL IN THE BLANK BELOW SO beverage and numCups are read:
    // MOVE THE FOLLOWING TO INSIDE THE readInput function
    //       (MOVE ALL HIGHLIGHTED IN MAIN BELOW HERE)
	bool validBeverage;

	cout << endl << endl;
	cout << "Hot Beverage Menu" << endl << endl;
	cout << "A: Coffee         $1.00" << endl;
	cout << "B: Tea            $ .75" << endl;
	cout << "C: Hot Chocolate  $1.25" << endl;
	cout << "D: Cappuccino     $2.50" << endl;

	do {
	   // Fill in the code to read in beverage
		cin>>beverage;


		switch(beverage)
		{
			case 'a':
			case 'A':
			case 'b':
			case 'B':
			case 'c':
			case 'C':
			case 'd':
			case 'D': validBeverage = true;
				break;
			default:  cout<<"Invalid choice, enter a valid choice: ";
					validBeverage = false;
		} // end switch
	}while(!validBeverage); // LAST CHANGE

	string prompt = "How many cups would you like? ";
	numCups = getInteger(prompt, 1, 20);

}

int getInteger(string prompt,
		int minInt,
		int maxInt)
{
	int localInt;

	cout << prompt ;
	cin >> localInt;
	cin.ignore(); // remove '\n' or bad char.
	while( localInt < minInt || localInt > maxInt )
	{
		cout << "Invalid input, must be >= " << minInt
			<< " and <= " << maxInt << endl;
		cout << prompt;
		cin >> localInt;
		cin.ignore();
	} // end while
	return localInt;
} // end getInteger

double calcCost(char beverage, int numCups)
{
	// you finish
    double cost;
	   switch( beverage )
        {
            case 'a':
            case 'A': cost = numCups * 1.0;
                break;

            case 'b':
            case 'B': cost = numCups * 0.75;
                    break;
              case 'c':
              case 'C': cost = numCups * 1.25;
                    break;
              case 'd':
              case 'D': cost = numCups * 2.50;
                    break;

        } // end switch
	return cost;
}

