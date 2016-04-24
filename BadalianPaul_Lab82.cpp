// This program will read in a group of test scores( positive integers from 1 to 100)
// from the keyboard and then calculates and outputs  the average score
// as well as the highest and lowest score. There will be a maximum of 100 scores.

// PLACE YOUR NAME HERE

#include <iostream>
#include <fstream>

using namespace std;

const int ARRAY_SIZE=100;

float findAverage (int array[], int size);  // finds average of all grades
int   findHighest (int array[], int size);  // finds highest of all grades
int   findLowest  (int array[], int size);  // finds lowest of all grades
void selectionSort(int array[], int size);
void showArray(int array[], int size);
int numberOfAverageGrades(int array[], int size, int average);

int main()
{

    int  grades[ARRAY_SIZE];	  // the array holding the grades.

    int temp;               // variable for the input number

    int  numberOfGrades;  // the number of grades read.

    int pos;		  // index to the array.

	float avgOfGrades;   // contains the average of the grades.

	int highestGrade;    // contains the highest grade.

	int lowestGrade;     // contains the lowest grade.
	
	int numAboveAvg;

	ifstream inputFile("gradfile.txt");
	
	if(!inputFile){
		cout << "Error finding or reading input file." << endl;
		return 1;
	}



	pos=0;
	while(pos < ARRAY_SIZE && inputFile >> temp)
	{
        // Fill in the code to assign temp to the next element in intArray
		grades[pos] = temp;

        // Fill in the code to read the next number
		inputFile >> temp;
		
        ++pos;
	}// end for



	numberOfGrades = pos;  // Fill blank with appropriate identifier



	avgOfGrades = findAverage(grades, numberOfGrades);
	
	selectionSort(grades, numberOfGrades);
	
	numAboveAvg = numberOfAverageGrades(grades, numberOfGrades, avgOfGrades);
	
	showArray(grades, numberOfGrades);
	
	cout << numAboveAvg << " are above average." << endl;
	
	/*
	//  Fill in the call to the function that calculates highest grade

	highestGrade = findHighest(grades, numberOfGrades);


	// Fill in the call to the function that calculates lowest grade

	lowestGrade = findLowest(grades, numberOfGrades);

	cout << endl << "The average of all the grades is " << avgOfGrades << endl;

	cout << endl << "The highest grade is " << highestGrade << endl;

    // Fill in code to write the lowest to the screen

	cout << endl << "The lowest grade is " << lowestGrade << endl;
	*/

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

void showArray(int array[], int size)
{
   for (int count = 0; count < size; count++)
      cout << array[count] << " ";
   cout << endl;
} 

int numberOfAverageGrades(int array[], int size, int average){
	int counter = 0;
	for(int count = 0; count < size; count++){
		if(array[count] > average){
			counter++;
		}
	}
	
	return counter;
}
void selectionSort(int array[], int size)
{
   int startScan, minIndex, minValue;

   for (startScan = 0; startScan < (size - 1); startScan++)
   {
      minIndex = startScan;
      minValue = array[startScan];
      for(int index = startScan + 1; index < size; index++)
      {
         if (array[index] < minValue)
         {
            minValue = array[index];
            minIndex = index;
         }
      }
      array[minIndex] = array[startScan];
      array[startScan] = minValue;
   }
}

/* Output

The average of all the grades is 58.2

The highest grade is 90

The lowest grade is 21

*/