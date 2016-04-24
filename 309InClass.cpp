#include <iostream>
#include <string>
using namespace std;

// Function prototypes
void doubleArray(int [], int);
void showValues(int [], int, ofstream);// FIX SO IT HAS AN ostream & param.
// PUT FUNCTION PROTOTYPE DECLARATION FOR openOutputFile HERE:
bool openOutputFile(ofstream &outputFile);
int main()
{
   const int ARRAY_SIZE = 7;
   int set[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7};
   // DECLARE ofstream VARIABLE HERE!

   ofstream outputFile;

   // OPEN THE ofstream USING openOutputFile, and
   //     check if it returns false (if so, 
   //        display message and end program)
   if(!openOutputFile()){
	   cout << "Error opening output file" << endl;
	   return 1;
   }


   // Display the initial values.
   cout << "The arrays values are:\n";
   showValues(set, ARRAY_SIZE, outputFile);//ADD output file var. as argument

   // Double the values in the array.
   doubleArray(set, ARRAY_SIZE);

   // Display the resulting values.
   cout << "After calling doubleArray the values are:\n";
   showValues(set, ARRAY_SIZE, outputFile);//ADD output file var. as argument

   return 0;
}

//*****************************************************
// Definition of function doubleArray                 *
// This function doubles the value of each element    *
// in the array passed into nums. The value passed    *
// into size is the number of elements in the array.  *
//*****************************************************

void doubleArray(int nums[], int size)
{
   for (int index = 0; index < size; index++)
      nums[index] *= 2;
}

//**************************************************
// Definition of function showValues.              *
// This function accepts an array of integers and  *
// the array's size as its arguments. The contents *
// of the array are displayed.                     * 
//**************************************************

void showValues(int nums[], int size, ofstream outputFile)//ADD output file var. as parameter
{
   for (int index = 0; index < size; index++)
      outputFile << nums[index] << " "; // WRITE TO output file
   outputFile << endl; // WRITE TO output file
}
bool openOutputFile(ofstream &outputFile){
	string name;
	cout << "Enter name of file: ";
	getline(cin, name);
	outputFile.open(name.c_str());
	if(outputFile){
		return true;
	}
	return false;
}