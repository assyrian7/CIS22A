/***************************************************************************************************
*	Guessing Game Program
*
*	Programmer: Paul Badalian
*
*	Operating System: Windows 10
*
*	Compiler: MinGW g++.exe
*	
*	Description:
*	This program is a guessing game that asks the user to guess each number stored in the input file
*
*	CIS 22A Lee-Klawender
***************************************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

bool openInputFile(ifstream &inputFile); //Function prototype for open input file
void openOutputfile(ofstream &outputFile); //Function prototype for open output file
void selectionSort(int array[], int size); //Function prototype for selection sort 
void outputArray(ofstream &outputFile, int array[], int size); //Function prototype for output array
void guessingGame(int answer); //Function prototype for guessing game
int userGuess(int guessArray[], int size, int counter); //Function prototype for asking the user for a guess
bool sequentialSearch(int guessArray[], int size, int search); //Function prototype for sequential searching

const int MAIN_ARRAY_SIZE = 30; //Const for the max size of the main array
const int GAME_ARRAY_SIZE = 10; //Const for the max size of the guess array
const int RANGE = 100; //Const for the range of guesses

int main(){
	
	ifstream inputFile; //Declare inputFile variable
	ofstream outputFile; //Declare outputFile variable
	int mainArray[MAIN_ARRAY_SIZE]; //Declare int array for main array numbers
	int index = 0; //Declare local int index
	
	//Check to see if input file opens. If it doesn't, print an error and return 1
	if(!openInputFile(inputFile)){
		cout << "Error finding or opening input file" << endl;
		return 1;
	}
	
	//Loop through all of the ints in the input file as long as there is less than 30 ints
	while(index < MAIN_ARRAY_SIZE && inputFile >> mainArray[index]){
		cout << "\nNew Number.\n";
		guessingGame(mainArray[index]);
		index++;
	}
	
	inputFile.close(); //Close input file
	
	selectionSort(mainArray, index); //Sort the main array ints
	
	outputArray(outputFile, mainArray, index); //Print the main array to the output file
	
	
	return 0;
}
/****************************************************
*	This function processes the guessing game of the 
*   program. Ask the user for a guess and notify the
*   user how close he/she is to the target and 
*   provide the number of guesses left. 
****************************************************/
void guessingGame(int answer){
	
	int guess;
	int guessesLeft;
	int guessArray[GAME_ARRAY_SIZE];
	int counter = 0;
	
	while(counter < GAME_ARRAY_SIZE && guess != answer){
		guess = userGuess(guessArray, GAME_ARRAY_SIZE, counter);
		guessesLeft = GAME_ARRAY_SIZE - 1 - counter;
		if(guess > answer){
			cout << "Your guess is too high(" << guessesLeft << " guesses left)" << endl; 
		}
		else if(guess < answer){
			cout << "Your guess is too low(" << guessesLeft << " guesses left)" << endl; 
		}
		counter++;
	}
	
	if(guessArray[counter - 1] != answer){
		cout << "You ran out of guesses. The correct answer is " << answer << endl;
	}
	else{
		cout << "Your guess is correct! It took you " << counter << " tries." << endl;
	}
	
}
/****************************************************
*	This will ask the user to input a guess, store it
*   in the guess array, and return that value.
****************************************************/
int userGuess(int guessArray[], int size, int counter){
	int guess;
	cout << "Enter your guess: ";
	cin >> guess;
	while(guess < 0 || guess > RANGE || sequentialSearch(guessArray, counter, guess)){
		cout << "Your guess is either out of range or you have already guessed that. Enter again: ";
		cin >> guess;
	}
	guessArray[counter] = guess;
	
	return guess;
	
}
/****************************************************
*	This will analyze the array argument for a 
*	specific argument. Return a bool indicating
*	whether the target is in the array.
****************************************************/
bool sequentialSearch(int guessArray[], int size, int search){
	bool found = false;
	for(int i = 0; i < size; i++){
		if(search == guessArray[i]){
			found = true;
		}
	}
	return found;
}
/****************************************************
*	This will open the input file of the program
*	containing the input numbers. Ask the user for
*	the name and return whether it opens or not.
****************************************************/
bool openInputFile(ifstream &inputFile){
	string fileName;
	cout << "Enter the input file name: ";
	getline(cin, fileName);
	inputFile.open(fileName.c_str());
	if(!inputFile){
		return false;
	}
	return true;
}
/****************************************************
*	This will open the output file of the program
*
****************************************************/
void openOutputFile(ofstream &outputFile){
	outputFile.open("output.txt");
}
/****************************************************
*	This will print the main array of the program to
*	the output file declared in main. 
*
****************************************************/
void outputArray(ofstream &outputFile, int array[], int size){
	openOutputFile(outputFile);
	outputFile << "The Game numbers in sorted order:" << endl;
	for(int i = 0; i < size; i++){
		outputFile << setw(4) << right << array[i] << endl;
	}
}
/****************************************************
*	This will sort the array argument using the
*	selection sorting algorithm.
****************************************************/
void selectionSort(int array[], int size){
	int startScan, minIndex, minValue;
	for(startScan = 0; startScan < size - 1; startScan++){
		minIndex = startScan;
		minValue = array[startScan];
		for(int index = startScan + 1; index < size; index++){
			if(array[index] < minValue){
				minValue = array[index];
				minIndex = index;
			}
		}
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
	}
}
/* Output
Enter the input file name: input.txt

New Number.
Enter your guess: 20
Your guess is too high(9 guesses left)
Enter your guess: 18
Your guess is too low(8 guesses left)
Enter your guess: 19
Your guess is correct! It took you 3 tries.

New Number.
Enter your guess: 30
Your guess is too high(9 guesses left)
Enter your guess: 10
Your guess is too low(8 guesses left)
Enter your guess: 20
Your guess is too low(7 guesses left)
Enter your guess: 25
Your guess is too low(6 guesses left)
Enter your guess: 27
Your guess is too low(5 guesses left)
Enter your guess: 29
Your guess is too high(4 guesses left)
Enter your guess: 28
Your guess is correct! It took you 7 tries.

New Number.
Enter your guess: 30
Your guess is too low(9 guesses left)
Enter your guess: 29
Your guess is too low(8 guesses left)
Enter your guess: 29
Your guess is either out of range or you have already guessed that. Enter again:28
Your guess is too low(7 guesses left)
Enter your guess: 27
Your guess is too low(6 guesses left)
Enter your guess: 26
Your guess is too low(5 guesses left)
Enter your guess: 25
Your guess is too low(4 guesses left)
Enter your guess: 24
Your guess is too low(3 guesses left)
Enter your guess: 23
Your guess is too low(2 guesses left)
Enter your guess: 22
Your guess is too low(1 guesses left)
Enter your guess: 21
Your guess is too low(0 guesses left)
You ran out of guesses. The correct answer is 57

New Number.
Enter your guess: 20
Your guess is too low(9 guesses left)
Enter your guess: 40
Your guess is too low(8 guesses left)
Enter your guess: 60
Your guess is too low(7 guesses left)
Enter your guess: 80
Your guess is too low(6 guesses left)
Enter your guess: 90
Your guess is too high(5 guesses left)
Enter your guess: 85
Your guess is too high(4 guesses left)
Enter your guess: 83
Your guess is correct! It took you 7 tries.
*/

