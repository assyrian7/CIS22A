// This program will read in a group of test scores( positive integers from 1 to 100)
// from the keyboard and then calculates and outputs  the average score
// as well as the highest and lowest score. There will be a maximum of 100 scores.

// PLACE YOUR NAME HERE

#include <iostream>

using namespace std;

const int ARRAY_SIZE=100;

float findAverage (int array[], int size);  // finds average of all grades
int   findHighest (int array[], int size);  // finds highest of all grades
int   findLowest  (int array[], int size);  // finds lowest of all grades

int main()
{

    int  grades[ARRAY_SIZE];	  // the array holding the grades.

    int temp;               // variable for the input number

    int  numberOfGrades;  // the number of grades read.

    int pos;		  // index to the array.

	float avgOfGrades;   // contains the average of the grades.

	int highestGrade;    // contains the highest grade.

	int lowestGrade;     // contains the lowest grade.



	cout << "Please input a grade from 1 to 100, (or -99 to stop)" << endl;

	cin  >> temp;

	pos=0;
	while(pos < ARRAY_SIZE && temp != -99)
	{
        // Fill in the code to assign temp to the next element in intArray
		grades[pos] = temp;

        // Fill in the code to read the next number
		cin >> temp;
		
        ++pos;
	}// end for



	numberOfGrades = pos;  // Fill blank with appropriate identifier



	avgOfGrades = findAverage(grades, numberOfGrades);

	//  Fill in the call to the function that calculates highest grade

	highestGrade = findHighest(grades, numberOfGrades);


	// Fill in the call to the function that calculates lowest grade

	lowestGrade = findLowest(grades, numberOfGrades);

	cout << endl << "The average of all the grades is " << avgOfGrades << endl;

	cout << endl << "The highest grade is " << highestGrade << endl;

    // Fill in code to write the lowest to the screen

	cout << endl << "The lowest grade is " << lowestGrade << endl;
	

	return 0;
} // end main


//****************************************************************************
//                                 findAverage
//
// task:          This function receives an array of integers and its size.
//                It finds and returns the average of the numbers in the array
// data in:       array of floating point numbers, size
// data returned: avarage of the numbers in the array
//
//****************************************************************************

float findAverage (int array[], int size)
{
	float sum = 0;   // holds the sum of all the numbers

    if( size <=0 )
        return 0;

    for (int pos = 0; pos < size; pos++)
	   sum = sum + array[pos];

    return (sum / size);  //returns the average

}

//****************************************************************************
//                                 findHighest
//
// task:          This function receives an array of integers and its size.
//                It finds and returns the highest value of the numbers in
//                the array
// data in:       array of floating point numbers, size
// data returned: highest value of the numbers in the array
//
//***************************************************************************
int   findHighest (int array[], int size)
{

	int highest = -1;
	if(size <= 0)
		return highest;
	
	for(int pos = 0; pos < size; pos++){
		if(array[pos] > highest)
			highest = array[pos];
	}

	return highest;
} // end findHighest


//****************************************************************************
//                                 findLowest
//
// task:          This function receives an array of integers and its size.
//                It finds and returns the lowest value of the numbers in
//                the array
// data in:       array of floating point numbers, size
// data returned: lowest value of the numbers in the array
//
//****************************************************************************

int   findLowest  (int array[], int size)
{

   // Fill in the code for this function
   
   int lowest = 101;
   if(size <= 0)
	   return lowest;
	   
	for(int pos = 0; pos < size; pos++){
		if(array[pos] < lowest)
			lowest = array[pos];
	}

	return lowest;

} // end findLowest

/* Output

Please input a grade from 1 to 100, (or -99 to stop)
90
45
73
62
-99

The average of all the grades is 67.5

The highest grade is 90

The lowest grade is 45

*/