#include <iostream>

using namespace std;

void reverseArrayDouble(double array[], int size);
void showArray(double array[], int size);

const int SIZE = 7;

int main(){
	
	double arr[] = {3.1, 4.3, 5.67, 6.29, 7.14, 8.42, 9.74};
	
	showArray(arr, SIZE);
	
	reverseArrayDouble(arr, SIZE);
	
	showArray(arr, SIZE);	
	
	return 0;
	
}

void reverseArrayDouble(double array[], int size){
	
	double temp;
	
	for(int i = 0; i < size / 2; i++){
		temp = array[i];
		array[i] = array[size - 1 - i];
		array[size - 1 - i] = temp;
	}
	
}
void showArray(double arr[], int size){
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}