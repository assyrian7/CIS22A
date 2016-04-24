// This program will output the circumference and area

// of the circle with a given radius.

//  PLACE YOUR NAME HERE

#include <iostream>

using namespace std;



const  double PI = 3.14;

const  double RADIUS = 5.4;



int main()

{

	double area;			// declaration of area of circle

    double circumference;		// declaration of circumference

    circumference = 2 * PI * RADIUS;	// computes circumference

    area = PI * RADIUS * RADIUS;                // computes area using PI and RADIUS

	

   // Fill in the code for the cout statement that will output (with description)

   // the circumference USING the circumference variable
	
	cout << "The circumference of the circle is " << circumference << endl;
	

   // Fill in the code for the cout statement that will output (with description)

   // the area of the circle USING the area variable
   
   cout << "The area of the circle is " << area << endl;

	/*Output
	The circumference of the circle is 33.912
	The area of the circle is 91.5624
	*/

   return 0;

}
