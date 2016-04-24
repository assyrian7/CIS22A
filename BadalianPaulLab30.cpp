#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	double a, b, c;
	double root1, root2;
	
	cout << "Enter 3 coefficients of a quadratic equation: ";
	cin >> a >> b >> c;
	
	root1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	root2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	
	root1 = (double)(root1);
	root2 = (double)(root2);
	
	cout << "\nRoot 1 = " << root1 << endl;
	cout << "Root 2 = " << root2 << endl;
	
	
	
	return 0;
}
