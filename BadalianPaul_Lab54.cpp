#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
	
	ofstream outputFile;
	outputFile.open("MultTable.txt");
	if(outputFile){
		for(int i = 1; i <= 12; i++){
			for(int j = 1; j <= 12; j++){
				outputFile << setw(7) << i * j;
			}
			outputFile << endl;
		}
	}
	
	
	return 0;
}