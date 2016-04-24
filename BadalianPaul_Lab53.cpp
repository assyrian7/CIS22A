#include <iostream>

using namespace std;

int main(){
	
	int row = 1;
	while(row <= 5)
	{
		cout << endl;
		row++;
	}
	
	int col = 0;
	while(col < row)
	{
		cout << "*";
		col++;
	}
	cout << endl;
	for(row = 1; row <= 5; ++row)
	{
		for(col = 0; col < row; ++col)
			cout << "*";
		
		cout << endl;
	}	
	
	row = 1;
	while(row <= 5)
	{
		col = 0;
		while(col < row)
		{
			cout << "*";
			col++;
		}
		cout << endl;
		row++;
	}
	
	return 0;
}

/* Output

******
*
**
***
****
*****
*
**
***
****
*****

*/
