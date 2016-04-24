/*
*	Asterik Shapes Program
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
#include <fstream>
#include <cctype>

using namespace std;

bool readInput(char &input, ifstream &inputFile, int &int1, int &int2); //Declare read input function
void processShapeCode(ofstream &outputFile, char input, int int1, int int2); //Declare process shapes function
void writeParallelogram(ofstream &outputFile, int int1, int int2); //Declare parallelogram function
void writeRectangle(ofstream &outputFile, int int1, int int2); //Declare rectangle function
void writeTriangle(ofstream &outputFile, int int1); //Declare triangle function
void idFunction(int hwNum);

int main(){
	
	char input; //Declare input char for determining which shape to output
	int int1; //Declare int for number of rows for shapes
	int int2; //Declare int for number of asteriks to print per row
	
	ofstream outputFile("output.txt"); //Declare and open an output file object
	ifstream inputFile("input.txt"); //Declare and open an input file object
	
	idFunction(5); //Call idFunction

	
	if(!outputFile || !inputFile){ //Check to see if both files exist
		cout << "Error opening one or both files." << endl; //If error with either file exit program and print error
		return 1;
	}
	while(readInput(input, inputFile, int1, int2)){ //Loop for inputs in file until end of file
		processShapeCode(outputFile, input, int1, int2); //Process inputs and print shapes depending on inputs
	}
	
	
	
}
/************************************************
 Define idFunction function
 Print name and homework number depending on 
 parameter.
************************************************/
void idFunction(int hwNum){
	cout<<"CIS 22A Programming Homework # " << hwNum << endl;
	cout <<"Badalian, Paul"<< endl << endl;
}
/************************************************
 Define readInput function
 This function will read inputs from the input
 file and changes the input variables.
 If end of file, the function will return false.
 It will return true elsewise.
************************************************/
bool readInput(char &input, ifstream &inputFile, int &int1, int &int2){
	inputFile >> input; //Read for char input
	if(inputFile.eof()){ //Return false if end of file
		return false;
	}
	input = toupper(input); //Make input uppercase
	switch(input){ //Determine the ints to read depending on the input
		case 'P':
		case 'R':
			inputFile >> int1 >> int2;
			break;
		case 'S':
		case 'T':
			inputFile >> int1;
			break;
		default:
			cout << "Invalid shape specified in file: " << input << endl;
			inputFile.ignore(80, '\n'); //If invalid, ignore until next line
			break;
	}
}
/************************************************
 Define processShapeCode function. 
 This will switch through the input and determine
 which shape function to call.
************************************************/
void processShapeCode(ofstream &outputFile, char input, int int1, int int2){
	switch(input){ //Determine which shape to print depending on the input
		case 'P':
			writeParallelogram(outputFile, int1, int2);
			break;
		case 'R':
			writeRectangle(outputFile, int1, int2);
			break;
		case 'S':
			writeRectangle(outputFile, int1, int1);
			break;
		case 'T':
			writeTriangle(outputFile, int1);
			break;
		default:
			break;
	}
}
/************************************************
 Define writeParallelogram function. 
 This will print a parallelogram to the output
 file. It will loop with int1 as the number of 
 rows and int2 as the number of asteriks per 
 line.
************************************************/
void writeParallelogram(ofstream &outputFile, int int1, int int2){
	outputFile << endl;
	for(int i = 0; i < int1; i++){ //Loop through rows and print asteriks in shape of a parallelogram
		for(int j = 0; j < int2; j++){
			outputFile << "*";
		}
		outputFile << "\n";
		for(int h = 0; h <= i; h++){
			outputFile << " ";
		}
	}
}
/************************************************
 Define writeRectangle function. 
 This will print a rectangle to the output
 file. It will loop with int1 as the number of 
 rows and int2 as the number of asteriks per 
 line. If square, int1 will be used as the number
 of rows and asteriks per line.
************************************************/
void writeRectangle(ofstream &outputFile, int int1, int int2){
	outputFile << endl;
	for(int i = 0; i < int1; i++){ //Loop through rows and print asteriks in shape of a rectangle or square
		for(int j = 0; j < int2; j++){
			outputFile << "*";
		}
		outputFile << endl;
	}
}
/************************************************
 Define writeTriangle function. 
 This will print a right triangle to the output
 file. It will loop with int1 as the number of 
 rows and int2 as the number of asteriks per 
 line with int2 decreasing by 1 per line.
************************************************/
void writeTriangle(ofstream &outputFile, int int1){
	outputFile << endl;
	for(int i = int1; i > 0; i--){ //Loop through rows and print asteriks in shape of a right triangle
		for(int j = i; j > 0; j--){
			outputFile << "*";
		}
		outputFile << endl;
	}
}

