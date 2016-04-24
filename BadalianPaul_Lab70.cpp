// This program has a partially initialized array.
#include <iostream>
using namespace std;

int main()
{
   const int SIZE = 7;
   int numElems = 4;
   int numbers[SIZE] = {1, 2, 4, 8}; // Initialize first 4 elements

   cout << "Here are the contents of the array:\n";
   for (int index = 0; index < numElems; index++)
      cout << numbers[index] << " ";

   cout << endl;
   
   cout << "\nHere are the contents of the array backwards:\n";
   for (int index = numElems - 1; index >= 0; index--)
      cout << numbers[index] << " ";

   cout << endl;
   return 0;
}
/* Output 1
Here are the contents of the array:
1 2 4 8 0 0 0
*/

/* Output 2
Here are the contents of the array:
1 2 4 8
*/

/* Output 3
Here are the contents of the array backwards:
8 4 2 1
*/



