#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double TAX = 0.08675;

int main(){
	
	string itemOne, itemTwo;
	double numberOfItemsOne, numberOfItemsTwo;
	double priceOfItemOne, priceOfItemTwo;
	double priceOne, priceTwo;
	double total, tax;
	
	cout << "Enter the name of item one: ";
	getline(cin, itemOne);
	
	cout << "Enter the number of " << itemOne << "s and the price of each: ";
	cin >> numberOfItemsOne >> priceOfItemOne;
	
	
	cout << "Enter the name of item two: ";
	cin.ignore(10, '\n');
	getline(cin, itemTwo);
	
	cout << "Enter the number of " << itemTwo << "s and the price of each: ";
	cin >> numberOfItemsTwo >> priceOfItemTwo;
	
	priceOne = static_cast<double>(priceOfItemOne * numberOfItemsOne);
	priceTwo = static_cast<double>(priceOfItemTwo * numberOfItemsTwo);
	tax = static_cast<double>((priceOne + priceTwo) * TAX);
	total = static_cast<double>(priceOne + priceTwo + tax);
	
	cout << left << setw(20) << "Item" << right << setw(5) << "Count" << right << setw(10) << "Price" << endl;
	cout << left << setw(20) << "====" << right << setw(5) << "=====" << right << setw(10) << "=====" << endl;
	cout << left << setw(20) << itemOne << right << setw(5) << numberOfItemsOne << right << setw(10) << setprecision(2) << priceOne << endl;
	cout << left << setw(20) << itemTwo << right << setw(5) << numberOfItemsTwo << right << setw(10) << setprecision(2) << priceTwo << endl;
	cout << left << setw(20) << "Tax" << right << setw(5) << "" << right << setw(10) << setprecision(2) << tax << endl;
	cout << left << setw(20) << "Total" << right << setw(5) << "" << right << setw(10) << setprecision(2) << total << endl;


	return 0;
}

/* Output
Enter the name of item one: mechanical pencil
Enter then number of mechanical pencils and the price of each: 2 2.50
Enter the name of item two: binder
Enter the number of binders and the price of each: 3 7.25

Item                Count     Price
====                =====     =====
mechanical pencil       2         5
binder                  3        22
Tax                             2.3
Total                            29
*/
